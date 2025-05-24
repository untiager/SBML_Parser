/*
** EPITECH PROJECT, 2024
** SBML_parser
** File description:
** type_flag_id.c
*/

#include "../include/sbml.h"


int is_a_compartment(char *str, char *id)
{
    char **tab = my_str_to_word_array(str, " <>\t");
    char *to_search = malloc(sizeof(char) * 999);

    to_search = my_strcat(to_search, "id=\"");
    to_search = my_strcat(to_search, id);
    to_search = my_strcat(to_search, "\"/");
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], to_search) == 0 &&
        my_strcmp(tab[0], "compartment") == 0)
            return 1;
    }
    return 0;
}

int is_a_species(char *str, char *id)
{
    char **tab = my_str_to_word_array(str, " <>\t");
    char *to_search = malloc(sizeof(char) * 999);

    to_search = my_strcat(to_search, "id=\"");
    to_search = my_strcat(to_search, id);
    to_search = my_strcat(to_search, "\"/");
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], to_search) == 0 &&
        my_strcmp(tab[0], "species") == 0)
            return 1;
    }
    return 0;
}

int is_a_reaction(char *str, char *id)
{
    char **tab = my_str_to_word_array(str, " <>\t");
    char *to_search = malloc(sizeof(char) * 999);

    to_search = my_strcat(to_search, "id=\"");
    to_search = my_strcat(to_search, id);
    to_search = my_strcat(to_search, "\"");
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], to_search) == 0 &&
        my_strcmp(tab[0], "reaction") == 0)
            return 1;
    }
    return 0;
}

char *what_is_it(char **tab, char *id)
{
    for (int i = 0; tab[i] != NULL; i++){
        if (is_a_compartment(tab[i], id) == 1)
            return ("compartment");
        if (is_a_species(tab[i], id) == 1)
            return ("species");
        if (is_a_reaction(tab[i], id) == 1)
            return ("reaction");
    }
    return "nothing";
}
