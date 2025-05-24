/*
** EPITECH PROJECT, 2024
** SBML_parser
** File description:
** flag_id.c
*/

#include "../include/sbml.h"

static char **sort_stor(char **storage)
{
    for (int i = 0; i <= 100; i++)
        storage = sort_alphabetical_order(storage);
    return (storage);
}

static void print_storage_react(char **storage_of_reactions, char *id)
{
    my_printf("List of reactions consuming species %s (quantities)\n", id);
    for (int i = 0; storage_of_reactions[i] != NULL; i++) {
        if (my_strcmp(storage_of_reactions[i], "false") == 0)
            continue;
        my_printf("--->%s (1)\n", storage_of_reactions[i]);
    }
}

char *go_back_until_reaction(char **tab, int i)
{
    char *reaction = malloc(sizeof(char) * 999);

    for (int j = i; j >= 0; j--) {
        if (my_strncmp(tab[j], "Reaction", 7) == 0) {
            reaction = tab[j];
            return reaction;
        }
    }
    return "false";
}

static char **find_reactions(char **tab, char *id)
{
    char **storage_of_reactions = malloc(sizeof(char *) * 999);

    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], id) == 0) {
            storage_of_reactions[i] = go_back_until_reaction(tab, i);
        } else {
            storage_of_reactions[i] = "false";
        }
    }
    return storage_of_reactions;
}

static char *store_if_useful(char *str, char *id)
{
    char **tab = my_str_to_word_array(str, " <>\t");

    if (my_strcmp(tab[0], "reaction") != 0
    && my_strcmp(tab[0], "listOfReactants") != 0) {
        if (my_strcmp(tab[0], "speciesReference") != 0
        && my_strcmp(tab[0], "listOfProducts") != 0)
            return ("false");
    }
    return str;
}

char *store_id(char *str)
{
    char **tab = my_str_to_word_array(str, " \"=<>\t");

    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], "id") == 0)
            return (tab[i + 1]);
    }
    return "false";
}

char *store_species(char *str)
{
    char **tab = my_str_to_word_array(str, " \"=<>\t");

    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], "species") == 0)
            return (tab[i + 1]);
    }
    return "false";
}

char **find_useful(char **tab, char *id)
{
    char **new_tab = malloc(sizeof(char *) * 999);
    char **tab2 = malloc(sizeof(char *) * 999);

    for (int i = 0; tab[i] != NULL; i++) {
        new_tab[i] = store_if_useful(tab[i], id);
    }
    for (int g = 0; new_tab[g] != NULL; g++) {
        tab2 = my_str_to_word_array(new_tab[g], " <>\t");
        if (my_strcmp(tab2[0], "reaction") == 0) {
            new_tab[g] = store_id(new_tab[g]);
        }
        if (my_strcmp(tab2[0], "speciesReference") == 0) {
            new_tab[g] = store_species(new_tab[g]);
        }
    }
    return new_tab;
}

void species(char **tab, char *id)
{
    char **storage_of_reactions = malloc(sizeof(char *) * 999);
    char **new_tab = malloc(sizeof(char *) * 999);

    new_tab = find_useful(tab, id);
    storage_of_reactions = find_reactions(new_tab, id);
    storage_of_reactions = sort_stor(storage_of_reactions);
    print_storage_react(storage_of_reactions, id);
}
