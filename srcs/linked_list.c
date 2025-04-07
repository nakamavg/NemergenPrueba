// linked_list.c
#include "linked_list.h"
#include "nemergent.h"

#include <stdlib.h>

Node* create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return NULL; 
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node *add_node(Node *head, int data) {
    Node *new_node = create_node(data);
    if (new_node == NULL) {
        return NULL; 
    }
    if (head == NULL) {
        return new_node;
    }
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

void free_list(Node *head) {
    Node *current = head;
    Node *next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}

void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d\n",current->data);
        current = current->next;
    }
}