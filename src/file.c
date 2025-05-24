/*
** EPITECH PROJECT, 2024
** SBML_parser
** File description:
** requirement.c
*/

#include "../include/sbml.h"

int number_char_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int count = 0;
    char *buff = malloc(sizeof(char) * 9999999);

    if (fd == -1) {
        my_printf("Error: File not found\n");
        return (84);
    }
    if (read(fd, buff, 999999) == -1) {
        my_printf("Eroor: File can't be read\n");
        return (84);
    }
    while (buff[count] != '\0')
        count++;
    close(fd);
    free(buff);
    return count;
}

int nb_col_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size_file = 0;
    char *buff = NULL;
    int count = 0;

    if (number_char_file(filepath) == 84)
        return (84);
    size_file = number_char_file(filepath);
    buff = malloc(sizeof(char) * size_file);
    if (fd == -1)
        return (84);
    if (read(fd, buff, 99999) == -1)
        return (84);
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n')
            count++;
    }
    return count;
}

char **open_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size_file = number_char_file(filepath);
    char *buf = malloc(sizeof(char) * size_file);
    char **tab = malloc(sizeof(char *) * nb_col_file(filepath));

    if (nb_col_file(filepath) == 84)
        return NULL;
    if (fd == -1) {
        my_printf("Error: File can't be opened\n");
        return NULL;
    }
    if (read(fd, buf, size_file) == -1) {
        my_printf("Error: File can't be read\n");
        return NULL;
    }
    tab = my_str_to_word_array(buf, "\n");
    close(fd);
    return tab;
}
