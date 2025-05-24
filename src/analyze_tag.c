/*
** EPITECH PROJECT, 2024
** SBML_parser
** File description:
** main.c
*/

#include "../include/sbml.h"

int analyze_string(char *string)
{
    for (int j = 0; string[j] != '\0'; j++) {
        if (string[j] == '=')
            return 1;
    }
    return 0;
}

char **rm_first(char **tab)
{
    char **new_tab = malloc(sizeof(char *) * 9999);
    int ct = 0;

    for (int i = 1; tab[i] != NULL; i++){
        new_tab[ct] = tab[i];
        ct++;
    }
    return new_tab;
}

char **analyze_tag(char **original_tab)
{
    char **new_tab = malloc(sizeof(char *) * 9999);
    int ct = 0;

    for (int i = 0; original_tab[i] != NULL; i++) {
        if (analyze_string(original_tab[i]) == 1) {
            new_tab[ct] = original_tab[i];
            ct++;
        }
    }
    new_tab = rm_first(new_tab);
    new_tab[ct - 1] = NULL;
    return new_tab;
}
