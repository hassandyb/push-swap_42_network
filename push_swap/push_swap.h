/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:36:10 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/03/31 18:29:06 by hed-dyb          ###   ########.fr       */
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
	int data;
	struct s_stack *next;
} t_stack;

void ft_check(char **argv);
void	ft_check2(char **argv);
int	ft_strlen(char *s);
void ft_protection(char *to_check, char *to_free);
char	*ft_strjoin(char *stock, char *arg);
char	*ft_join_args(char **argv);
int	ft_count(char *stock);
char	*ft_substr(char *stock, int begin, int len, char **split);
char **ft_split(char *stock);
void ft_free_double_pointer(char **s);
void	ft_protection_double_ptr(char **to_check, char *to_free);
void ft_push(t_stack **push_from, t_stack **push_to, char *msg);



#endif