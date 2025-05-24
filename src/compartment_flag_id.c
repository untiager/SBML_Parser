/*
** EPITECH PROJECT, 2024
** SBML_parser
** File description:
** flag_id.c
*/

#include "../include/sbml.h"

char *after_equal(char *tab)
{
    char **tab2 = my_str_to_word_array(tab, "=\"");

    return tab2[1];
}

void find_name2(char *name, char **tab, int i)
{
    if (verify_if_i_have_equal(tab[i + 1]) == 0) {
        name = my_strcat(name, " ");
        name = my_strcat(name, tab[i + 1]);
        name[my_strlen(name) - 1] = '\0';
    }
}

char *find_name(char **tab)
{
    char *name = malloc(sizeof(char) * 999);

    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strncmp(tab[i], "name=", 4) == 0) {
            name = my_strcat(name, after_equal(tab[i]));
            find_name2(name, tab, i);
        }
    }
    return (name);
}

char *analyze_line_comp(char *str, char *id)
{
    char **tab = my_str_to_word_array(str, " <>\t");
    char *to_search = malloc(sizeof(char) * 999);
    char *name = malloc(sizeof(char) * 999);

    if (my_strcmp(tab[0], "species") != 0)
        return "false";
    to_search = my_strcat(to_search, "compartment=\"");
    to_search = my_strcat(to_search, id);
    to_search = my_strcat(to_search, "\"");
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], to_search) == 0) {
            name = find_name(tab);
        }
    }
    return (name);
}

void compartment(char **tab, char *id)
{
    char **storage_of_name = malloc(sizeof(char *) * 999);

    my_printf("List of species in compartment %s\n", id);
    for (int i = 0; tab[i] != NULL; i++)
        storage_of_name[i] = analyze_line_comp(tab[i], id);
    storage_of_name = sort_alphabetical_order(storage_of_name);
    for (int i = 0; storage_of_name[i] != NULL; i++) {
        if (my_strcmp(storage_of_name[i], "false") != 0)
            my_printf("--->%s\n", storage_of_name[i]);
    }
}
