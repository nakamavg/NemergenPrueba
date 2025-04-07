// linked_list.c
#include "linked_list.h"
#include "nemergent.h"
#include <stdlib.h>

/**
 * @brief Crea un nuevo nodo para una lista enlazada
 */
Node* create_node(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    pthread_mutex_init(&node->mutex, NULL); 
    return node;
}

/**
 * @brief Añade un nuevo nodo al final de una lista enlazada
 */
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

/**
 * @brief Libera toda la memoria utilizada por una lista enlazada
 */
void free_list(Node **list) {
    Node *current = *list;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        pthread_mutex_destroy(&temp->mutex);
        free(temp);
    }
    *list = NULL;
}

/**
 * @brief Imprime todos los elementos de una lista enlazada
 */
void print_list(Node *head)
{
    Node *current = head;
    bool first = true;
    while (current != NULL)
    {
        if(!first)
            printf(", ");
        else
            first = false;
        printf("%d", current->data);
        current = current->next;
    }
}

/**
 * @brief Inserta un elemento en la lista de forma segura (thread-safe)
 */
void safe_insert(Node **list, int data)
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