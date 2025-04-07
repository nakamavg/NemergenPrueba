#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node *next;
    pthread_mutex_t mutex;

} Node;

Node* create_node(int data);
Node* add_node(Node *head, int data);
void free_list(Node *head);
void print_list(Node *head);

#endif