/*
** EPITECH PROJECT, 2024
** SBML_parser
** File description:
** main.c
*/

#include "../include/sbml.h"

int error(int ac)
{
    if (ac == 3) {
        my_printf("Error: need something after the flag -i\n");
        return 0;
    }
    if (ac < 2) {
        my_printf("Error: Invalid number of arguments\n");
        return 84;
    }
    return 1;
}
