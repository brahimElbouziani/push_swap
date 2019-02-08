# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 16:38:07 by bel-bouz          #+#    #+#              #
#    Updated: 2019/01/14 13:57:28 by bel-bouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = push_swap

all : $(NAME)

$(NAME):
	gcc $(FLAGS) -c ft_helper.c ft_strdup.c ft_strnew.c ft_split_whitespaces.c ft_verifie.c ft_get_next_line.c finding_value.c ft_lib.c ft_instrection.c ft_instrection2.c ft_modife.c ft_affiche.c  -I.
	gcc $(FLAGS) ft_push_swap.c *.o -o $@
	gcc $(FLAGS) ft_checker.c  *.o -o checker

clean :
	/bin/rm -f *.o

fclean : clean
	/bin/rm -f push_swap
	/bin/rm -f checker

re : fclean all  