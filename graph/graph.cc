#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <memory>

enum COLOR{
    WHITE,
    GRAY,
    BLOCAK
};


class node{
public:
    int _id;
    std::shared_ptr<node> _prenode;
    COLOR color;
    int d;
    node(int id):_id(id),_prenode(nullptr),color(WHITE),d(-1){}
    bool operator==(node &n){
        return this->_id==n._id;
    }
};


using nodeptr = std::shared_ptr<node>;
using graph = std::vector<std::list<nodeptr>>;


#define make_node(i) nodeptr n##i=std::make_shared<node>(i)


//广度优先搜索
void BFS(graph &g,nodeptr &n){
    std::queue<nodeptr> q;
    n->d = 0;
    n->color = GRAY;
    q.push(n);
    while(!q.empty()){
        nodeptr nod = q.front();
        q.pop();
        for(auto &nods:g[nod->_id-1]){
            if(*nods==*nod) continue;
            if(nods->color==WHITE){
                nods->color = GRAY;
                nods->d = nod->d + 1;
                q.push(nods);
            }
        }
        nod->color = BLOCAK;
        std::cout<<"[id]="<<nod->_id<<" [d]="<<nod->d<<std::endl;
    }
}




int main(){
    make_node(1);
    make_node(2);
    make_node(3);
    make_node(4);
    make_node(5);
    make_node(6);


    graph g = {{n1,n2,n5},{n2,n1,n5,n3,n4},{n3,n2,n4},{n4,n2,n5,n3},{n5,n4,n1,n2}};
    std::cout<<"hello world"<<std::endl;
    BFS(g,n3);
}