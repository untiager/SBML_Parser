/*
** EPITECH PROJECT, 2024
** SBML_parser
** File description:
** change_ver.c
*/

#include "../include/sbml.h"

int is_reversible(char **str)
{
    int ver = 0;
    char **tab = malloc(sizeof(char *) * 999);

    for (int i = 0; str[i] != NULL; i++) {
        tab = my_str_to_word_array(str[i], " <>\t");
        if (my_strncmp(tab[0], "reversible=\"true\"", 16) == 0) {
            return 1;
        }
    }
    return 0;
}

int search_id(char *str, char *to_search)
{
    char **tab = my_str_to_word_array(str, " <>\t");
    char **storage_of_att = malloc(sizeof(char *) * 999);
    int rev = 0;

    if (my_strcmp(tab[0], "reaction") != 0)
        return 0;
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], to_search) == 0) {
            rev = is_reversible(tab);
            return rev;
        }
    }
    return rev;
}

int change_ver(char **tab, char *id)
{
    char **tab2 = analyze_tag(tab);
    char *to_search = malloc(sizeof(char) * 999);
    int ver = 0;

    to_search = my_strcat(to_search, "id=\"");
    to_search = my_strcat(to_search, id);
    to_search = my_strcat(to_search, "\"");
    for (int i = 0; tab[i] != NULL; i++) {
        ver = search_id(tab[i], to_search);
        if (ver == 1)
            return 1;
    }
    return ver;
}
