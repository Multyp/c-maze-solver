/*
** EPITECH PROJECT, 2023
** DANTE
** File description:
** queue_funcs
*/

#include "graph.h"
#include <stdlib.h>

queue *create_queue()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(queue *q, node *data)
{
    queue_node *new_node = (queue_node *)malloc(sizeof(queue_node));
    new_node->data = data;
    new_node->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = new_node;
        return;
    }

    q->rear->next = new_node;
    q->rear = new_node;
}

node *dequeue(queue *q)
{
    if (q->front == NULL)
        return NULL;

    queue_node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    node *data = temp->data;
    free(temp);

    return data;
}

int is_empty(queue *q)
{
    return q->front == NULL;
}

void free_queue(queue *q)
{
    while (!is_empty(q)) {
        dequeue(q);
    }
    free(q);
}
