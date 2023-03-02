/*
** EPITECH PROJECT, 2022
** MY_PUTCHAR
** File description:
** J'accepte tous types de dons.
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
