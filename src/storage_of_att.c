/*
** EPITECH PROJECT, 2024
** SBML_parser
** File description:
** main.c
*/

#include "../include/sbml.h"

char **move_before_if_empty(char **storage_of_att)
{
    int i = 0;
    int g = 0;
    char **tmp = malloc(sizeof(char *) * 999);

    while (i <= 100) {
        if (storage_of_att[i] != NULL) {
            tmp[g] = storage_of_att[i];
            g++;
        }
        i++;
    }
    return tmp;
}

char **store_before_equal(char *str, char **storage_of_att, int i)
{
    char **tab = my_str_to_word_array(str, "=");

    storage_of_att[i] = tab[0];
    return storage_of_att;
}

char **sort_alphabetical_order(char **tab)
{
    char *tmp = NULL;
    int i = 0;

    while (i <= 100){
        if (tab[i] == NULL || tab[i + 1] == NULL){
            i++;
            continue;
        }
        if (my_strcmp(tab[i], tab[i + 1]) > 0) {
            tmp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = tmp;
            i = 0;
        }
        i++;
    }
    return tab;
}

char **format_storage(char **storage)
{
    storage = move_before_if_empty(storage);
    for (int i = 0; i <= 100; i++)
        storage = sort_alphabetical_order(storage);
    return storage;
}
