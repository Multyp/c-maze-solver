/*
** EPITECH PROJECT, 2023
** DANTE
** File description:
** graph_create
*/

#include <stdlib.h>
#include <string.h>
#include "graph.h"

void set_index(node **graph, char *line, int row, int col)
{
    init_graph_index(graph, row, col);
    set_wall(graph, line, row, col);
    set_path(graph, line, row, col);
}

int check_line(char *line, int read)
{
    if (line[read - 1] == '\n') {
        line[read - 1] = line[read];
    }
    read = strlen(line);
    return read;
}

void get_maze_size(FILE *fp, char *filename, int *num_rows, int *num_cols)
{
    char *line = NULL;
    size_t len = 0;
    int read;

    read = getline(&line, &len, fp);
    *num_cols = read - 1;
    struct stat mystat;

    stat(filename, &mystat);
    check_cols(mystat, read, num_cols);
    *num_rows = (int)(mystat.st_size / (read)) + 1;

    free(line);
}

void end_create(char *line, FILE *fp, FILE *fp2)
{
    free(line);
    fclose(fp);
    fclose(fp2);
}

node **create_graph(char *filename, int *num_rows, int *num_cols)
{
    FILE *fp = fopen(filename, "r"), *fp2 = fopen(filename, "r");
    char *line = NULL;
    size_t len = 0;
    int row = 0, col = 0, read = 0;

    check_fp(fp);
    get_maze_size(fp, filename, num_rows, num_cols);
    node **graph = (node **)malloc(*num_rows * sizeof(node *));

    while ((read = getline(&line, &len, fp2)) != -1) {

        read = check_line(line, read);
        read != *num_cols ? exit_no_rect(graph, line, num_cols, row) : (void)0;
        graph[row] = (node *)malloc(*num_cols * sizeof(node));

        for (col = 0; col < read; col++) {
            set_index(graph, line, row, col);
            line[col] != 'X' && line[col] != '*' ?
            exit_banned_char(graph, line, row, num_cols) : (void)0;
        }
        row++;
    }
    end_create(line, fp, fp2);

    return graph;
}
