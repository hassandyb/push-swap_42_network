# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 15:43:04 by hed-dyb           #+#    #+#              #
#    Updated: 2023/04/15 21:33:39 by hed-dyb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
LIBRARY = mandatory/push_swap.h
BONUS_LIBRARY = bonus/push_swap_bonus.h
CC = cc 
RM = rm -f

FLAGS = -Wall -Werror -Wextra
FILES = mandatory/array.c mandatory/final_sort.c mandatory/first_sort.c \
					mandatory/functions.c mandatory/instractions.c \
					mandatory/instractions_2.c mandatory/less_than_5.c \
					mandatory/protection.c mandatory/push_swap.c \
					mandatory/split.c

OBJ = $(FILES:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(LIBRARY) $(BONUS_LIBRARY)
	$(CC) $(FLAGS) $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)
	
re : fclean all




