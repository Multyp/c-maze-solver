/*
** EPITECH PROJECT, 2023
** ARRAY
** File description:
** Functions for arrays
*/

#include <stdlib.h>
void my_putchar(char c);
void my_putstr(char const *str);

int my_arrlen(char **array)
{
    int i = 0;
    if (array != NULL) {
        while (array[i] != 0)
            i++;
    }
    return i;
}

void print_arr(char ** arg)
{
    while (*arg) {
        my_putstr(*arg);
        arg++;
    }
}

void destroy_arr(char **array, int i)
{
    while (i >= 0)
        free(array[i--]);
    free(array);
}
