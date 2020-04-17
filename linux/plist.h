//
// Created by spinors on 20-4-17.
//

#ifndef LINUX_PLIST_H
#define LINUX_PLIST_H
struct list_head {
    struct list_head *prev;
    struct list_head *next;
};

struct plist_head {
    struct list_head node_list;
};

struct plist_node {
    int			prio;
    struct list_head prio_list;
    struct list_head node_list;
};

static inline bool list_empty(struct list_head *head){
    return (head->prev==head) && (head->next==head);
}

static void list_add_tail(struct list_head *node,struct list_head *head){
    node->prev = head->prev;
    node->next = head;
    node->prev->next = node;
    head->prev = node;
}

#define list_entry(list,type,member) ((type *)((char *)list - offsetof(type,member)))


void plist_add(struct plist_node *node,struct plist_head *head);


void plist_test();
#endif //LINUX_PLIST_H
