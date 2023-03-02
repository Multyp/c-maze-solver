/*
** EPITECH PROJECT, 2023
** DANTE
** File description:
** Main file for Dante
*/

#include <stddef.h>
#include "solver.h"
#include "graph.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        return 84;
    } else {
        int num_rows = 0, num_cols = 0;
        node **map = create_graph(argv[1], &num_rows, &num_cols);
        if (map[0][0].neighbors == NULL ||
        map[num_rows - 1][num_cols - 1].neighbors == NULL) {
            no_angles(map, &num_rows, &num_cols);
        }
        solve_maze(map, num_rows, num_cols);
        print_maze(map, num_rows, num_cols);
        free_graph(map, num_rows, num_cols);
        return 0;
    }
    return 0;
}
