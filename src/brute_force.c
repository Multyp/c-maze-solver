/*
** EPITECH PROJECT, 2023
** DANTE
** File description:
** brute_force
*/

#include "graph.h"

void go_back(node **graph, int num_rows, int num_cols)
{
    node *current = &graph[num_rows - 1][num_cols - 1];
    while (current != NULL) {
        current->visited = 2;
        current = current->parent;
    }
}

void solve_maze(node **graph, int num_rows, int num_cols)
{
    queue *q = create_queue();
    graph[0][0].visited = 1;
    enqueue(q, &graph[0][0]);

    while (!is_empty(q)) {
        node *current = dequeue(q);
         for (int i = 0; i < current->num_neighbors; i++) {
            node *neighbor = current->neighbors[i];

            if (!neighbor->visited) {
                neighbor->visited = 1;
                neighbor->parent = current;
                enqueue(q, neighbor);
            }
        }
    }
    go_back(graph, num_rows, num_cols);
    free_queue(q);
    return;
}
