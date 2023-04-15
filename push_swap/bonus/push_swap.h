/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:36:10 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/15 14:43:26 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				rank;
	int				data;
	struct s_stack	*next;
}	t_stack;

void	ft_check1(char **argv);
void	ft_check2(char **argv);
void	ft_check3(char **argv);
void	ft_check_args(int argc, char **argv);
int		ft_strlen(char *s);
void	ft_protection(char *to_check, char *to_free);
char	*ft_strjoin(char *stock, char *arg);
char	*ft_join_args(char **argv);
int		ft_count(char *stock);
char	*ft_substr(char *stock, int begin, int len, char **split);
char	**ft_split(char *stock);
void	ft_free_double_pointer(char **s);
void	ft_protection_double_ptr(char **to_check, char *to_free);
int		ft_arraylen(char **split);
void	ft_putstr(char *str);
void	ft_error(char **to_free, char *msg);
int		ft_atoi(char *s, char **to_free);
int		*ft_creat_array(char **split, int len);
void	ft_no_doubles(int *numbers, int len);
void	ft_not_sorted(int *numbers, int len);
void	ft_free_linked_list(t_stack *ptr);
void	ft_linked_list_protection(int *array, t_stack *to_check,
			t_stack *begin);
t_stack	*ft_create_stack_a(int *numbers, int len);
void	ft_push(t_stack **src, t_stack **dst, char *msg);
void	ft_rotate(t_stack **ptr, char *msg);
void	ft_swap(t_stack **ptr, char *msg);
void	ft_reverse_rotate(t_stack **ptr, char *msg);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_sort_array(int *numbers, int len);
void	ft_add_rank(t_stack *ptr, int *numbers, int len);
int		ft_wich_chunk(int len);
void	ft_sort_with_chunk(t_stack **a, t_stack **b, int len);
int		ft_maxnumber_indice(t_stack *list, int len);
void	ft_push_2_in_right(t_stack **b, t_stack **a, int len);
void	ft_push_2_in_left(t_stack **b, t_stack **a, int len);
void	ft_final_sort(t_stack **b, t_stack **a, int len);
int		ft_normal_case(t_stack **b, t_stack **a, int len, int indice);
void	ft_sort_3_numbers(t_stack **a, int min_rank);
void	ft_sort_5_numbers(t_stack **a, t_stack **b);
void	ft_less_than_five(t_stack **a, t_stack **b, int len);

#endif