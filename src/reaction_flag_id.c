/*
** EPITECH PROJECT, 2024
** SBML_parser
** File description:
** flag_id.c
*/

#include "../include/sbml.h"

void print_react_and_prod(char **storage_of_reactants,
    char **storage_of_products, char *id)
{
    my_printf("List of reactants of reaction %s\n", id);
    for (int i = 0; storage_of_reactants[i] != NULL; i++) {
        if (my_strcmp(storage_of_reactants[i], "false") == 0)
            continue;
        my_printf("--->%s\n", storage_of_reactants[i]);
    }
    my_printf("List of products of reaction %s\n", id);
    for (int i = 0; storage_of_products[i] != NULL; i++) {
        if (my_strcmp(storage_of_products[i], "false") == 0)
            continue;
        my_printf("--->%s\n", storage_of_products[i]);
    }
}

static char *get_reactants(char **tab, int i)
{
    char *list_of_reactants = malloc(sizeof(char) * 999);
    char **verif = my_str_to_word_array(tab[i + 1], " <>\t");
    char **cond = malloc(sizeof(char *) * 999);

    if (my_strcmp(verif[0], "listOfReactants") != 0)
        return "false";
    for (int j = i + 2; tab[j] != NULL; j++) {
        cond = my_str_to_word_array(tab[j], " <>\t");
        if (my_strcmp(cond[0], "/listOfReactants") == 0) {
            return list_of_reactants;
        }
        list_of_reactants = my_strcat(list_of_reactants, tab[j]);
    }
    return "false";
}

static char *get_products(char **tab, int i)
{
    char *list_of_products = malloc(sizeof(char) * 999);
    char **cond = malloc(sizeof(char *) * 999);
    char **verif = my_str_to_word_array(tab[i], " <>\t");

    while (my_strcmp(verif[0], "listOfProducts") != 0) {
        verif = my_str_to_word_array(tab[i], " <>\t");
        i++;
    }
    for (int j = i; tab[j] != NULL; j++) {
        cond = my_str_to_word_array(tab[j], " <>\t");
        if (my_strcmp(cond[0], "/listOfProducts") == 0) {
            return list_of_products;
        }
        list_of_products = my_strcat(list_of_products, tab[j]);
    }
    return "false";
}

static char *cut_useless_info2(char *str, char *to_search, int i)
{
    char **tab = my_str_to_word_array(str, " <>\t");
    char *new_str = malloc(sizeof(char) * 999);

    for (int j = 0; tab[j] != NULL; j++) {
        if (my_strcmp(tab[j], to_search) == 0) {
            new_str = str;
            return new_str;
        }
    }
    return "false";
}

static char **cut_useless_info(char **tab, char *id)
{
    char **new_tab = malloc(sizeof(char *) * 999);
    char *to_search = malloc(sizeof(char) * 999);

    to_search = my_strcat(to_search, "id=\"");
    to_search = my_strcat(to_search, id);
    to_search = my_strcat(to_search, "\"");
    for (int i = 0; tab[i] != NULL; i++) {
        new_tab[i] = cut_useless_info2(tab[i], to_search, i);
        if (my_strcmp(new_tab[i], "false") != 0) {
            new_tab[i] = malloc(sizeof(char) * 999);
            new_tab[i] = get_reactants(tab, i);
            new_tab[i + 1] = malloc(sizeof(char) * 999);
            new_tab[i + 1] = get_products(tab, i);
            return new_tab;
        }
    }
    return new_tab;
}

char *get_species(char *str)
{
    char **tab = my_str_to_word_array(str, " <>\t");
    char *species = malloc(sizeof(char) * 999);

    if (my_strcmp(tab[0], "speciesReference") != 0)
        return "false";
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strncmp(tab[i], "species=", 7) == 0) {
            species = my_strcat(species, after_equal(tab[i]));
        }
    }
    return species;
}

static char **sort_stor(char **storage)
{
    for (int j = 0; j <= 100; j++)
        storage = sort_alphabetical_order(storage);
}

char **fill_reactants(char **tab, char *id)
{
    char **storage = malloc(sizeof(char *) * 999);
    int ct = 0;
    char **to_pass = malloc(sizeof(char *) * 999);

    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], "false") == 0)
            continue;
        to_pass = my_str_to_word_array(tab[i], "<>\t");
        for (int a = 1; to_pass[a] != NULL; a++) {
            storage[ct] = get_species(to_pass[a]);
            ct++;
        }
        storage = sort_stor(storage);
        return storage;
    }
    storage = sort_stor(storage);
    return storage;
}

char **fill_products(char **tab, char *id)
{
    char **storage = malloc(sizeof(char *) * 999);
    char **to_pass = malloc(sizeof(char *) * 999);
    int ct = 0;
    int var = 0;

    for (int i = 1; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], "false") == 0)
            continue;
        if (my_strcmp(tab[i], "false") != 0 && var == 0) {
            var = 1;
            continue;
        }
        to_pass = my_str_to_word_array(tab[i], "<>\t");
        for (int a = 1; to_pass[a] != NULL; a++) {
            storage[ct] = get_species(to_pass[a]);
            ct++;
        }
        storage = sort_stor(storage);
        return storage;
    }
}

void reaction(char **tab, char *id, char **av, int ac)
{
    char **storage_of_reactants = malloc(sizeof(char *) * 999);
    char **storage_of_products = malloc(sizeof(char *) * 999);
    char **new_tab = malloc(sizeof(char *) * 999);
    int rev = 1;

    new_tab = cut_useless_info(tab, id);
    storage_of_reactants = fill_reactants(new_tab, id);
    storage_of_products = fill_products(new_tab, id);
    if (ac == 4)
        print_react_and_prod(storage_of_reactants, storage_of_products, id);
    if (ac == 5 && my_strcmp(av[4], "-e") == 0) {
        rev = change_ver(tab, id);
        print_flag_e(storage_of_reactants, storage_of_products, id, rev);
    }
    if (ac == 5 && my_strcmp(av[4], "-json") == 0)
        return;
    free(new_tab);
    free(storage_of_reactants);
    free(storage_of_products);
}
