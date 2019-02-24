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
    void insert(node * nod);
    void erase(node * nod);

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