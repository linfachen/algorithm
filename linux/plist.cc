//
// Created by spinors on 20-4-17.
//
#include <iostream>
#include <vector>

#include "plist.h"
static inline void init_plist_node(struct plist_node *node,int prio){
    node->prio = prio;
    node->node_list.prev = node->node_list.next = &(node->node_list);
    node->prio_list.prev = node->prio_list.next = &(node->prio_list);
}



void plist_add(struct plist_node *node,struct plist_head *head){
    struct list_head *node_next = &head->node_list;

    if(!list_empty(node_next)){
        struct plist_node *first,*iter;
        first = iter = list_entry(node_next->next,struct plist_node,node_list);
        struct plist_node *prev = nullptr;

        do {
            if (node->prio < iter->prio) {
                node_next = &iter->node_list;
                break;
            }

            prev = iter;
            iter = list_entry(iter->prio_list.next,struct plist_node,prio_list);
        }while(iter!=first);

        if(!prev || prev->prio!=node->prio){
            list_add_tail(&(node->prio_list),&(iter->prio_list));
        }
    }

    list_add_tail(&(node->node_list),node_next);
}

void plist_test(){
    std::vector<int> prio = {0,1,5,6,5,0,4,9,4,1};
    plist_head head = {&(head.node_list),&(head.node_list)};
    for(int i:prio){
        struct plist_node *node = new plist_node;
        init_plist_node(node,i);
        plist_add(node,&head);
    }

    for(list_head *first=head.node_list.next;first!=&(head.node_list);first=first->next){
        struct plist_node *node = list_entry(first,struct plist_node,node_list);
        std::cout<<node->prio<<std::endl;
    }
}