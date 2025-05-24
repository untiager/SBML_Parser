/*
** EPITECH PROJECT, 2024
** SBML_parser
** File description:
** requirement.c
*/

#include "../include/sbml.h"

storage_t *init_storage(void)
{
    storage_t *storage = malloc(sizeof(storage_t));

    storage->storage_of_attribute = malloc(sizeof(char *) * 100);
    storage->tag = malloc(sizeof(char *) * 1);
    storage->next = NULL;
    return storage;
}
