/*
** EPITECH PROJECT, 2024
** sbml parser
** File description:
** sbml.h
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "myprintf.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef SBML_H
    #define SBML_H

typedef struct storage_s {
    char *tag;
    char **storage_of_attribute;
    struct storage_s *next;
}storage_t;

char **open_file(char *filepath);
char **analyze_tag(char **original_tab);
char **format_storage(char **storage);
char **sort_alphabetical_order(char **tab);
char **store_before_equal(char *str, char **storage_of_att, int i);
char **move_before_if_empty(char **storage_of_att);
storage_t *init_storage(void);
int verify_if_flag_id(char **av, int ac);
void sbml_id(char **av, int ac);
char *what_is_it(char **tab, char *id);
int verify_if_i_have_equal(char *str);
void compartment(char **tab, char *id);
void nothing(char **tab);
void species(char **tab, char *id);
void reaction(char **tab, char *id, char **av, int ac);
char *after_equal(char *tab);
int verify_if_flag_h(char **av, int ac);
void print_help(void);
void print_flag_e(char **storage_react,
    char **storage_prod, char *id, int rev);
int change_ver(char **tab, char *id);
int error(int ac);

#endif // SBML_H
