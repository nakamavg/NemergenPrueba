// linked_list.c
#include "linked_list.h"
#include "nemergent.h"

#include <stdlib.h>

// lists.c
Node* create_node(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    pthread_mutex_init(&node->mutex, NULL); 
    return node;
}

Node *add_node(Node *head, int data)
{
    Node *new_node = create_node(data);
    if (new_node == NULL)
    {
        return NULL;
    }
    if (head == NULL)
    {
        return new_node;
    }
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

// lists.c
void free_list(Node **list) {
    Node *current = *list;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        pthread_mutex_destroy(&temp->mutex); // Destruir mutex del nodo
        free(temp);
    }
    *list = NULL;
}

void print_list(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }

}

void safe_insert(Node * *list, int data)
{
    Node *new_node = create_node(data);
    if (!new_node)
        return;

    if (*list == NULL)
    {
        *list = new_node;
        return;
    }

    pthread_mutex_lock(&(*list)->mutex);
    Node *current = *list;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
    pthread_mutex_unlock(&(*list)->mutex);
}