# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcot <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 13:48:00 by gcot              #+#    #+#              #
#    Updated: 2023/05/03 15:02:28 by gcot             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUSN = checker

CC = gcc

SRC = main.c algo.c rules_1.c rules_2.c rules_3.c trie.c push_swap_error.c push_swap_utils.c push_swap_utils2.c ft_split.c radix.c algo_big.c

BONUS = check.c check2.c get_next_line.c get_next_line_utils.c algo.c rules_1.c rules_2.c rules_3.c trie.c push_swap_error.c push_swap_utils.c push_swap_utils2.c ft_split.c radix.c algo_big.c

OBJ = *.o

FLAGS = -Wall -Werror -Wextra

all :
	gcc $(FLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME) $(BONUSN)

re : fclean all

bonus : all
	gcc $(FLAGS) $(BONUS) -o $(BONUSN)
