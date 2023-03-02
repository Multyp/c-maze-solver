/*
** EPITECH PROJECT, 2023
** DANTE
** File description:
** graph_utils
*/

#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

void free_graph(node **graph, int num_rows, int num_cols)
{
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            free(graph[i][j].neighbors);
        }
        free(graph[i]);
    }
    free(graph);
}

void print_maze(node **graph, int num_rows, int num_cols)
{
    for (int i = 0; i < num_rows; i++) {

        for (int j = 0; j < num_cols; j++) {
            graph[i][j].visited == 2 ? printf("o") :
            printf("%c", graph[i][j].c);
        }
        printf("\n");
    }
}
