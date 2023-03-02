/*
** EPITECH PROJECT, 2023
** DANTE
** File description:
** graph
*/

#ifndef GRAPH_H_
    #define GRAPH_H_
    #include <stdio.h>
    #include <sys/stat.h>
    #include <stdbool.h>

    typedef struct node {
        int x;
        int y;
        struct node **neighbors;
        struct node *parent;
        int num_neighbors;
        char c;
        int visited;
    } node;

    typedef struct node_info {
        int f;
        int g;
    } node_info;

    typedef struct queue_node {
        node *data;
        struct queue_node *next;
    } queue_node;

    typedef struct queue {
        queue_node *front;
        queue_node *rear;
    } queue;

    /*graph_create.c*/

    node **create_graph(char *filename, int *num_rows, int *num_cols);
    void end_create(char *line, FILE *fp, FILE *fp2);
    void get_maze_size(FILE *fp, char *filename, int *num_rows, int *num_cols);
    int check_line(char *line, int read);
    void set_index(node **graph, char *line, int row, int col);

    /*graph_error.c*/

    void no_angles(node **graph, int *num_rows, int *num_cols);
    void exit_banned_char(node **graph, char *line, int row, int *num_cols);
    void exit_no_rect(node **graph, char *line, int *num_cols, int row);
    void check_cols(struct stat mystat, int read, int *num_cols);
    void check_fp(FILE *fp);

    /*graph_setup.c*/

    void init_graph_index(node **graph, int row, int col);
    void set_col_neighbors(node **graph, int row, int col);
    void set_row_neighbors(node **graph, int row, int col);
    void set_path(node **graph, char *line, int row, int col);
    void set_wall(node **graph, char *line, int row, int col);

    /*graph_utils.c*/

    void print_maze(node **graph, int num_rows, int num_cols);
    void free_graph(node **graph, int num_rows, int num_cols);

    /*queue_funcs.c*/

    void free_queue(queue *q);
    int is_empty(queue *q);
    node *dequeue(queue *q);
    void enqueue(queue *q, node *data);
    queue *create_queue();

    /*brute_force.c*/

    void solve_maze(node **graph, int num_rows, int num_cols);
    void go_back(node **graph, int num_rows, int num_cols);

#endif /* !GRAPH_H_ */
