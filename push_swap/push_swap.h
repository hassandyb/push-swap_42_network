/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:36:10 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/05 18:38:07 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <string.h>
typedef struct s_stack
{
	int rank;
	int data;
	struct s_stack *next;
} t_stack;

void ft_check1(char **argv);
void	ft_check2(char **argv);
void ft_check3(char **argv);
int	ft_strlen(char *s);
void ft_protection(char *to_check, char *to_free);
char	*ft_strjoin(char *stock, char *arg);
char	*ft_join_args(char **argv);

int	ft_count(char *stock);
char	*ft_substr(char *stock, int begin, int len, char **split);
char **ft_split(char *stock);
void ft_free_double_pointer(char **s);
void	ft_protection_double_ptr(char **to_check, char *to_free);
int ft_arraylen(char **split);
void ft_putstr(char *str);
void ft_error(char **to_free, char *msg);
//
int ft_atoi(char *s, char **to_free);
int *ft_creat_array(char **split, int len);
void	ft_no_doubles(int *numbers, int len);
void	ft_not_sorted(int *numbers, int len);

void	ft_free_linked_list(t_stack *ptr);
void ft_linked_list_protection(int *array, t_stack *to_check, t_stack *begin);
t_stack	*ft_create_stack_a(int *numbers, int len);

void ft_push(t_stack **src, t_stack **dst, char *msg);
void ft_rotate(t_stack **ptr, char *msg);
void ft_swap(t_stack **ptr, char *msg);
void ft_reverse_rotate(t_stack **ptr, char *msg);



#endif