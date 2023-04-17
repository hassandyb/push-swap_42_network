# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 15:43:04 by hed-dyb           #+#    #+#              #
#    Updated: 2023/04/17 00:31:35 by hed-dyb          ###   ########.fr        #
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
BONUS_FILES = bonus/array_bonus.c bonus/extra_bonus.c bonus/functions_bonus.c \
					bonus/instractions_2_bonus.c bonus/instractions_bonus.c \
					bonus/protection_bonus.c bonus/push_swap_bonus.c \
					bonus/split_bonus.c bonus/get_next_line_bonus.c \
					bonus/get_next_line_utils_bonus.c

OBJ = $(FILES:%.c=%.o)

BONUS_OBJ = $(BONUS_FILES:%.c=%.o)

all : $(NAME)

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJ)
		$(CC) $(FLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

#why -c because (cause we need object files) - using cc => the compiler will try to make an excutable!!

%.o : %.c $(LIBRARY) $(BONUS_LIBRARY)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)
	$(RM) $(BONUS_OBJ)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	
re : fclean all




