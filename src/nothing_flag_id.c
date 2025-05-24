/*
** EPITECH PROJECT, 2024
** SBML_parser
** File description:
** flag_id.c
*/

#include "../include/sbml.h"

void find_name_species2(char *name, char **tab, int i)
{
    if (verify_if_i_have_equal(tab[i + 1]) == 0) {
        name = my_strcat(name, " ");
        name = my_strcat(name, tab[i + 1]);
        name[my_strlen(name) - 1] = '\0';
    }
}

char *find_name_species(char *str)
{
    char **tab = my_str_to_word_array(str, " <>\t");
    char *name = malloc(sizeof(char) * 999);

    if (my_strcmp(tab[0], "species") != 0)
        return "false";
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strncmp(tab[i], "name=", 4) == 0) {
            name = my_strcat(name, after_equal(tab[i]));
            find_name_species2(name, tab, i);
        }
    }
    return (name);
}

void nothing(char **tab)
{
    char **storage_of_name = malloc(sizeof(char *) * 999);

    my_printf("List of species\n");
    for (int i = 0; tab[i] != NULL; i++)
        storage_of_name[i] = find_name_species(tab[i]);
    for (int i = 0; i <= 100; i++)
        storage_of_name = sort_alphabetical_order(storage_of_name);
    for (int i = 0; storage_of_name[i] != NULL; i++) {
        if (my_strcmp(storage_of_name[i], "false") == 0)
            continue;
        my_printf("--->%s\n", storage_of_name[i]);
    }
}
