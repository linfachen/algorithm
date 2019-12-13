//
// Created by spinors on 19-12-13.
//
#include <vector>
#include <iostream>

class node{
public:
    int rank;
    int root;
    node():rank(0),root(-1){}
};


class Union_set{
public:
    std::vector<node> _set;
    void insert();
    void do_union(int a,int b);
    int find_set(int index);

    Union_set(){}
    Union_set(int n){
        _set.resize(n);
    }
};

int _find_set(std::vector<node> &_set,int index){
    if(index>=_set.size()) return -1;
    if(_set[index].root==-1) return index;
    int res = _find_set(_set,_set[index].root);
    _set[index].root = res;
    return res;
}

void Union_set::insert(){
    _set.emplace_back();
}

void Union_set::do_union(int a, int b) {
    int index_a = _find_set(_set,a);
    int index_b = _find_set(_set,b);
    if(index_a==-1){
        insert();
        index_a = _set.size()-1;
    }

    if(index_b==-1){
        insert();
        index_b = _set.size()-1;
    }

    if(_set[index_a].rank<_set[index_b].rank){
        _set[index_a].root = index_b;
    }else{
        _set[index_b].root = index_a;
        if(_set[index_a].rank==_set[index_b].rank) _set[index_a].rank++;
    }
}

int Union_set::find_set(int index){
    return _find_set(_set,index);
}


int main(){
    Union_set union_set;

    union_set.do_union(0,1);
    union_set.do_union(1,2);
    union_set.do_union(1,3);
    union_set.do_union(4,5);
    union_set.do_union(6,7);
    union_set.do_union(8,9);
    union_set.do_union(4,9);

    for(int i=0;i<10;i++){
        std::cout<<union_set.find_set(i)<<std::endl;
    }

}