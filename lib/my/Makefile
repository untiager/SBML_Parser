##
## EPITECH PROJECT, 2023
## lib/my
## File description:
## Makefile
##

# Directories
OBJDIR		=	../../obj
INCDIR		=	../../include
LIBDIR		=	../../lib

# Commands for creating directories
MKDIR_P		=	mkdir -p

# Command for removing files
RM			=	rm -rf

SRC			=	my_putchar.c				\
				concat_params.c				\
				my_arraylen.c				\
				my_char_is_alpha.c			\
				my_char_is_num.c			\
				my_compute_power_it.c		\
				my_isneg.c					\
				my_memset.c					\
				my_put_nbr.c				\
				my_strdup.c					\
				my_strndup.c				\
				my_swap.c					\
				my_putstr.c					\
				my_strlen.c					\
				my_getnbr.c					\
				my_sort_str.c				\
				my_sort_int_array.c			\
				my_str_to_word_array.c		\
				my_show_word_array.c		\
				my_compute_power_rec.c		\
				my_compute_square_root.c	\
				my_is_prime.c				\
				my_find_prime_sup.c			\
				my_free_array.c				\
				my_strcpy.c					\
				my_strncpy.c				\
				my_revstr.c					\
				my_strstr.c					\
				my_strcmp.c					\
				my_strcmp2.c				\
				my_strncmp.c				\
				my_strupcase.c				\
				my_strlowcase.c				\
				my_strcapitalize.c			\
				my_str_isalpha.c			\
				my_str_isnum.c				\
				my_str_islower.c			\
				my_str_isupper.c			\
				my_str_isprintable.c		\
				my_showstr.c				\
				my_showmem.c				\
				my_strcat.c					\
				my_strncat.c

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-Wall

INCLUDE		=	my.h

NAME		=	libmy.a

all: libmy copy

directory:
		@$(MKDIR_P) $(OBJDIR)

$(OBJDIR)/%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@

libmy: $(OBJ)
		@ar rc $(NAME) $(OBJ)

copy: libmy
		@cp $(INCLUDE) $(INCDIR)/$(INCLUDE)
		@cp $(NAME) $(LIBDIR)/$(NAME)

clean:
		@$(RM) $(OBJ)

fclean: clean
		@$(RM) $(LIBDIR)/$(NAME)
		@$(RM) $(LIBDIR)/my/$(NAME)

re: fclean all

.PHONY: all directory libmy copy clean fclean re
