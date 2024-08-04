# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 15:43:04 by hed-dyb           #+#    #+#              #
#    Updated: 2023/04/17 13:32:38 by hed-dyb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBRARY = push_swap.h

CC = cc 
RM = rm -f

FLAGS = -Wall -Werror -Wextra
FILES = array.c final_sort.c first_sort.c \
					functions.c instractions.c \
					instractions_2.c less_than_5.c \
					protection.c push_swap.c \
					split.c


OBJ = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(LIBRARY)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

	
re : fclean all




