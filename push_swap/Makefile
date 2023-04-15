# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 15:43:04 by hed-dyb           #+#    #+#              #
#    Updated: 2023/04/15 16:16:10 by hed-dyb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
LIBRARY = mandatory/push_swap.h
BONUS_LIBRARY = bonus/push_swap_bonus.h
CC = cc 
RM = rm -f
AR = ar r #r stand for replace ==>means=> you want to replace or add members to an existing static library. This can be useful in cases where you have made changes to the source files that are part of a library and you want to update the library with the new object files without recreating the entire library from scratch.
FLAGS = -Wall -Werror -Wextra
FILES = mandatory/array.c mandatory/final_sort.c mandatory/final_sort.c \
					mandatory/functions.c mandatory/instractions.c \
					mandatory/instractions_2.c mandatory/less_than_5.c \
					mandatory/protection.c mandatory/push_swap.c \
					mandatory/split.c
					
OBJ = $(FILES:%.c=%.o)

all : $(NAME)

$(NAME) = $(OBJ)
		$(AR) $(NAME) $(OBJ)

%.o : %.c $(LIBRARY) $(BONUS_LIBRARY)
		$(CC) $(FLAGS) $(OBJ) $< -o $@
		
clean :
	$(RM) $(OBJ)

fclean clean
		$(RM) $(NAME)

re : fclean all
