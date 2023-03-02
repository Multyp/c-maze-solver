/*
** EPITECH PROJECT, 2023
** DANTE
** File description:
** graph_content
*/

#include <stdlib.h>
#include "graph.h"

void set_wall(node **graph, char *line, int row, int col)
{
    if (line[col] == 'X') {
        graph[row][col].neighbors = NULL;
        graph[row][col].c = 'X';
    }
}

void set_path(node **graph, char *line, int row, int col)
{
    if (line[col] == '*') {
        graph[row][col].c = '*';
        graph[row][col].neighbors = (node **)malloc(4 * sizeof(node *));
        set_row_neighbors(graph, row, col);
        set_col_neighbors(graph, row, col);
    }
}

void set_row_neighbors(node **graph, int row, int col)
{
    if (row > 0 && graph[row - 1][col].neighbors != NULL) {
        graph[row][col].neighbors[graph[row][col].num_neighbors++] =
        &graph[row - 1][col];
        graph[row - 1][col].neighbors[graph[row - 1][col].num_neighbors++] =
        &graph[row][col];
    }
}

void set_col_neighbors(node **graph, int row, int col)
{
    if (col > 0 && graph[row][col - 1].neighbors != NULL) {
        graph[row][col].neighbors[graph[row][col].num_neighbors++] =
        &graph[row][col - 1];
        graph[row][col - 1].neighbors[graph[row][col - 1].num_neighbors++] =
        &graph[row][col];
    }
}

void init_graph_index(node **graph, int row, int col)
{
    graph[row][col].x = col;
    graph[row][col].y = row;
    graph[row][col].num_neighbors = 0;
    graph[row][col].parent = NULL;
    graph[row][col].visited = 0;
}
