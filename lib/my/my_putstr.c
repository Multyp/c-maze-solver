/*
** EPITECH PROJECT, 2022
** MY_PUTSTR
** File description:
** Printing a string.
*/

#include <unistd.h>

void my_putstr(char const *str)
{
    int i;
    for (i = 0; str[i]; i++) {
        write(STDOUT_FILENO, &str[i], 1);
    }
}
