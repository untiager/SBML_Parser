/*
** EPITECH PROJECT, 2024
** SBML_parser
** File description:
** main.c
*/

#include "../include/sbml.h"

int verify_if_i_have_equal(char *str)
{
    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == '=')
            return 1;
    }
    return 0;
}

static void print_storage_of_attribute(char **storage)
{
    for (int i = 0; storage[i] != NULL; i++)
        my_printf("--->%s\n", storage[i]);
}

storage_t *add_info_to_list(char *tag, char **storage_of_att, storage_t *list)
{
    storage_t *tmp = list;
    storage_t *new = malloc(sizeof(storage_t));

    new->tag = tag;
    new->storage_of_attribute = storage_of_att;
    new->next = NULL;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return list;
}

static char *printing(char *str, char **storage, storage_t *list)
{
    char **tab = my_str_to_word_array(str, " <>\t");
    char **storage_of_att = malloc(sizeof(char *) * 999);

    for (int i = 0; storage[i] != NULL; i++) {
        if (my_strncmp(storage[i], tab[0], my_strlen(tab[0])) == 0)
            return "false";
    }
    for (int i = 1; tab[i] != NULL; i++) {
        if (verify_if_i_have_equal(tab[i]) == 0)
            continue;
        storage_of_att = store_before_equal(tab[i], storage_of_att, i);
    }
    storage_of_att = format_storage(storage_of_att);
    list = add_info_to_list(tab[0], storage_of_att, list);
    return tab[0];
}

void print_list(storage_t *list)
{
    storage_t *tmp = list;

    while (tmp != NULL){
        if (tmp->tag != NULL && tmp->tag[0] != '\0')
            my_printf("%s\n", tmp->tag);
        print_storage_of_attribute(tmp->storage_of_attribute);
        tmp = tmp->next;
    }
}

static void sort_alphabetical_by_tag2(storage_t *tmp2, char *tmp_tag,
    char **tmp_storage)
{
    if (my_strcmp(tmp2->tag, tmp2->next->tag) > 0) {
        tmp_tag = tmp2->tag;
        tmp_storage = tmp2->storage_of_attribute;
        tmp2->tag = tmp2->next->tag;
        tmp2->storage_of_attribute = tmp2->next->storage_of_attribute;
        tmp2->next->tag = tmp_tag;
        tmp2->next->storage_of_attribute = tmp_storage;
    }
}

storage_t *sort_alphabetical_by_tag(storage_t *list)
{
    storage_t *tmp = list;
    storage_t *tmp2 = list;
    char *tmp_tag = NULL;
    char **tmp_storage = NULL;

    while (tmp->next != NULL) {
        while (tmp2->next != NULL) {
            sort_alphabetical_by_tag2(tmp2, tmp_tag, tmp_storage);
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
    return list;
}

static void free_all(char **tab, char **storage_of_tag)
{
    free(tab);
    free(storage_of_tag);
}

static void sbml(char **av)
{
    char **tab = analyze_tag(open_file(av[1]));
    char **storage_of_tag = malloc(sizeof(char *) *1000);
    storage_t *list_stor = init_storage();

    for (int i = 0; tab[i] != NULL; i++){
        storage_of_tag[i] = printing(tab[i], storage_of_tag, list_stor);
    }
    for (int i = 0; i <= 100; i++)
        list_stor = sort_alphabetical_by_tag(list_stor);
    print_list(list_stor);
    free_all(tab, storage_of_tag);
}

int main(int ac, char **av)
{
    int er = error(ac);

    if (er != 1)
        return er;
    if (ac == 2) {
        if (verify_if_flag_h(av, ac) == 1) {
            print_help();
            return 0;
        }
        sbml(av);
    }
    if (ac > 2) {
        if (verify_if_flag_id(av, ac) == 1)
            sbml_id(av, ac);
        else {
            my_printf("Error: Invalid flag\n");
            return 84;
        }
    }
    return 0;
}
