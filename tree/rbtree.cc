#include <iostream>


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
    void erase(int key);
    void print_node(node *nod,int high);
    //node * find_node(int key);
    void search();

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
void rbtree::print_node(node *nod,int high){
    if(nod->left!=&nil) print_node(nod->left,high+1);
    std::string color_str = nod->color==RED? "RED":"BLACK";
    std::string left_str = nod->left==&nil? "nil":std::to_string(nod->left->_id);
    std::string right_str = nod->right==&nil? "nil":std::to_string(nod->right->_id);
    std::cout<<"[id]="<<nod->_id<<" [color]="<<color_str<<" [high]="<<high<<" [left]="<<left_str<<" [right]="<<right_str<<std::endl;
    if(nod->right!=&nil) print_node(nod->right,high+1);
}

void rbtree::search(){
    if(_root==&nil) return;
    print_node(_root,1);
}

//==========================================================================================
//旋转节点
void left_rot(node *nod){
    node *father = nod->father;
    node *left = nod->left;
    nod->father = father->father;
    nod->left = father;
    left->father = father;
    father->father = nod;
    father->right = left;
}

void right_rot(node *nod){
    node *father = nod->father;
    node *right = nod->right;
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
        if(nod->)
    }
}





//==========================================================================================



void test_rbtree(){
    rbtree tree;
    tree.insert(5);
    tree.insert(1);
    tree.insert(6);
    tree.insert(112);
    tree.insert(0);
    tree.insert(24);
    tree.insert(0);

    tree.search();
}





