/*
** EPITECH PROJECT, 2024
** SBML_parser
** File description:
** flag_h.c
*/

#include "../include/sbml.h"

int verify_if_flag_h(char **av, int ac)
{
    if (ac < 2)
        return 0;
    for (int i = 0; av[i] != NULL; i++) {
        if (my_strcmp(av[i], "-h") == 0)
            return 1;
    }
    return 0;
}

void print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./SBMLparser SBMLfile [-i ID [-e]] [-json]\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    SBMLfile SBML file\n");
    my_putstr("    -i ID id of the compartment, reaction or ");
    my_putstr("species to be extracted (ignored if not provided)\n");
    my_putstr("    -e print the equation if a reaction ID is provided");
    my_putstr(" (ignored otherwise)\n");
    my_putstr("    -json convert the SBML file into a JSON file ");
    my_putstr("(ignored otherwise)\n");
}
