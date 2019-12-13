#include <iostream>

#define is_left(nod) ((nod)->father->left==(nod))
#define is_right(nod) ((nod)->father->right==(nod))


enum COLOR{
    RED,
    BLACK
};

class node{
public:
    int _id;
    COLOR color;
    node *father;
    node *left;
    node *right;

    node(int id);
    node();
};

class rbtree{
public:
    node *_root;
    node nil;
    bool insert(int key);
    bool erase(int key);
    void print_node(node *nod,int high);
    //node * find_node(int key);
    void search();
    void left_rot(node *nod);
    void right_rot(node *nod);
    rbtree();
};



node::node(int id){
    _id = id;
    color = BLACK;
    father = left = right = nullptr;
}

node::node(){
    _id = 0;
    color = BLACK;
    father = left = right = nullptr;
}

rbtree::rbtree(){
    _root = &nil;
}

//==========================================================================================
//遍历整rbtree
//void rbtree::print_node(node *nod,int high){
//    if(nod->left!=&nil) print_node(nod->left,high+1);
//    std::string color_str = nod->color==RED? "RED":"BLACK";
//    std::string left_str = nod->left==&nil? "nil":std::to_string(nod->left->_id);
//    std::string right_str = nod->right==&nil? "nil":std::to_string(nod->right->_id);
//    std::cout<<"[id]="<<nod->_id<<" [color]="<<color_str<<" [high]="<<high<<" [left]="<<left_str<<" [right]="<<right_str<<std::endl;
//    if(nod->right!=&nil) print_node(nod->right,high+1);
//}

void rbtree::print_node(node *nod,int balck_num){
    if(nod->color==BLACK) balck_num++;
    if(nod->left!=&nil) print_node(nod->left,balck_num);
    std::string color_str = nod->color==RED? "RED":"BLACK";
    std::string left_str = nod->left==&nil? "nil":std::to_string(nod->left->_id);
    std::string right_str = nod->right==&nil? "nil":std::to_string(nod->right->_id);
    std::cout<<"[id]="<<nod->_id<<" [color]="<<color_str<<" [left]="<<left_str<<" [right]="<<right_str<<std::endl;
    if(nod->left==&nil && nod->right==&nil){
        std::cout<<" [balck_num]="<<balck_num<<std::endl;
    }
    if(nod->color==RED && nod->father->color==RED){
        std::cout<<"it is not a rb-tree!!!"<<std::endl;
    }
    if(nod->right!=&nil) print_node(nod->right,balck_num);
}

void rbtree::search(){
    if(_root==&nil) return;
    print_node(_root,0);
}

//==========================================================================================
//旋转节点
inline void rbtree::left_rot(node *nod){
    node *father = nod->father;
    node *left = nod->left;
    if(father->father==&nil){
        _root = nod;
    }else if(is_left(father)){
        father->father->left = nod;
    }else{
        father->father->right = nod;
    }
    nod->father = father->father;
    nod->left = father;
    left->father = father;
    father->father = nod;
    father->right = left;
}

inline void rbtree::right_rot(node *nod){
    node *father = nod->father;
    node *right = nod->right;
    if(father->father==&nil){
        _root = nod;
    }else if(is_left(father)){
        father->father->left = nod;
    }else{
        father->father->right = nod;
    }
    nod->father = father->father;
    nod->right = father;
    right->father = father;
    father->father = nod;
    father->left = right;
}

//==========================================================================================
//插入元素
#define LEFT -1
#define ROOT 0
#define RIGHT 1



std::pair<node *,int> find_insert(rbtree &tree,int key){
    if(tree._root==&tree.nil) return std::make_pair(&tree.nil,ROOT);
    node * nod = tree._root;
    while(true){
        if(nod->_id==key){
            std::cout<<"[key]="<<key<<" is already exists!"<<std::endl;
            return std::make_pair(nullptr,ROOT);
        }
        if(nod->_id>key){
            if(nod->left==&tree.nil) return std::make_pair(nod,LEFT);
            nod = nod->left;
            continue;
        }else{
            if(nod->right==&tree.nil) return std::make_pair(nod,RIGHT);
            nod = nod->right;
            continue;
        }
    }
}


bool rbtree::insert(int key) {
    node * nod = new node(key);
    std::pair<node *,int> res = find_insert(*this,key);

    //insert node
    if(!res.first){
        return false;
    }else{
        nod->father = res.first;
        nod->left = nod->right = &nil;
        nod->color = RED;
    }

    if(res.second==ROOT){
        _root = nod;
        nod->color = BLACK;
    }else if(res.second==LEFT){
        res.first->left = nod;
    }else{
        res.first->right = nod;
    }

    //fix rb-tree
    while(nod->father->color==RED){
        if(is_left(nod->father)){
            if(nod->father->father->right->color==RED){
                nod->father->father->color=RED;
                nod->father->color=BLACK;
                nod->father->father->right->color=BLACK;
                nod = nod->father->father;
                if(_root==nod) nod->color=BLACK;
                continue;
            }
            if(is_left(nod)){
                nod->father->color = BLACK;
                nod->father->father->color = RED;
                right_rot(nod->father);
                break;
            }else{
                left_rot(nod);
                nod = nod->left;
            }
        }else{
            if(nod->father->father->left->color==RED){
                nod->father->father->color=RED;
                nod->father->color=BLACK;
                nod->father->father->left->color=BLACK;
                nod = nod->father->father;
                if(_root==nod) nod->color=BLACK;
                continue;
            }
            if(is_right(nod)){
                nod->father->color = BLACK;
                nod->father->father->color = RED;
                left_rot(nod->father);
                break;
            }else{
                right_rot(nod);
                nod = nod->right;
            }
        }
    }
}





//==========================================================================================
//删除元素
void find_after(int key){

}

bool rbtree::erase(int key){
    node *nod = _root;
    while(nod->_id!=key){
        if(nod->_id>key && nod->left!=&nil) {
            nod = nod->left;
        }else if(nod->_id<key && nod->right!=&nil){
            nod = nod->right;
        }else{
            std::cout<<"[key]="<<key<<" is not exists!"<<std::endl;
            return false;
        }
    }

    //delete nod;



}

//==========================================================================================
void test_rbtree(){
    rbtree tree;
    tree.insert(0);
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);
    tree.insert(10);
    tree.insert(11);
    tree.insert(12);
    tree.insert(13);
    tree.insert(14);
    tree.insert(15);
    tree.insert(16);
    tree.insert(-2);
    tree.insert(-36);
    tree.insert(-33);

    tree.search();
}





