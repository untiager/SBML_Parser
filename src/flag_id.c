/*
** EPITECH PROJECT, 2024
** SBML_parser
** File description:
** flag_id.c
*/

#include "../include/sbml.h"

int verify_if_flag_id(char **av, int ac)
{
    if (ac < 4)
        return 0;
    for (int i = 0; av[i] != NULL; i++) {
        if (my_strcmp(av[i], "-i") == 0)
            return 1;
    }
    return 0;
}

void sbml_id(char **av, int ac)
{
    char **tab = analyze_tag(open_file(av[1]));
    char *id = av[3];
    char *type = what_is_it(tab, id);

    if (my_strcmp(type, "compartment") == 0)
        compartment(tab, id);
    if (my_strcmp(type, "species") == 0)
        species(open_file(av[1]), id);
    if (my_strcmp(type, "reaction") == 0)
        reaction(open_file(av[1]), id, av, ac);
    if (my_strcmp(type, "nothing") == 0)
        nothing(tab);
}
