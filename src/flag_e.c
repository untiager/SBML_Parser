/*
** EPITECH PROJECT, 2024
** SBML_parser
** File description:
** flag_e.c
*/

#include "../include/sbml.h"

void print_react(char **storage_react)
{
    for (int i = 0; storage_react[i] != NULL; i++) {
        if (my_strcmp(storage_react[i], "false") == 0)
            continue;
        my_printf("1 %s ", storage_react[i]);
        if (my_strcmp(storage_react[i + 1], "false") != 0 &&
        storage_react[i + 1] != NULL)
            my_printf("+ ");
    }
}

void print_prod(char **storage_prod)
{
    for (int i = 0; storage_prod[i] != NULL; i++) {
        if (my_strcmp(storage_prod[i], "false") == 0)
            continue;
        my_printf("1 %s ", storage_prod[i]);
        if (my_strcmp(storage_prod[i + 1], "false") != 0 &&
        storage_prod[i + 1] != NULL)
            my_printf("+ ");
    }
}

void print_sign(int rev)
{
    if (rev == 1)
        my_printf("<-> ");
    else
        my_printf(" -> ");
}

void print_flag_e(char **storage_react,
    char **storage_prod, char *id, int rev)
{
    print_react(storage_react);
    print_sign(rev);
    print_prod(storage_prod);
    my_printf("\n");
    return;
}
