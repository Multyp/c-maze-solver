/*
** EPITECH PROJECT, 2023
** DANTE
** File description:
** graph_error
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "graph.h"

void check_fp(FILE *fp)
{
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(84);
    }
}

void check_cols(struct stat mystat, int read, int *num_cols)
{
    if ((mystat.st_size % read != *num_cols)) {
        printf("Error: Maze is not rectangular.\n");
        exit(84);
    }
}

void exit_no_rect(node **graph, char *line, int *num_cols, int row)
{
    printf("Error: Maze is not rectangular.\n");
    free(line);
    free_graph(graph, row, *num_cols);
    exit(84);
}

void exit_banned_char(node **graph, char *line, int row, int *num_cols)
{
    printf("Error: Invalid character in maze.\n");
    free(line);
    free_graph(graph, row + 1, *num_cols);
    exit(84);
}

void no_angles(node **graph, int *num_rows, int *num_cols)
{
    printf("Error: Maze does not have a valid start or finish node.\n");
    free_graph(graph, *num_rows, *num_cols);
    exit(84);
}
