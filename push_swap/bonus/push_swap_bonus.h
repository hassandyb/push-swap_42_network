/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:50:06 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/16 21:57:20 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	6
# endif


typedef struct s_stack
{
	int				rank;
	int				data;
	struct s_stack	*next;
}	t_stack;

char	*get_next_line(int fd);
char	*get_after_newline(char *stock);
int		ft_line_len(char *str);
int		ft_strchr( char *str, char c);
char	*ft_strjoin(char *s1, char *s2);


void	ft_check1(char **argv);
void	ft_check2(char **argv);
void	ft_check3(char **argv);
void	ft_check_args(int argc, char **argv);
int	ft_count(char *stock);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_substr_2(char *stock, int begin, int len, char **split);
char	**ft_split(char *stock);
char	*ft_join_args(char **argv);
int	ft_atoi(char *s, char **to_free);
void	ft_no_doubles(int *numbers, int len);
void	ft_not_one_number_or_sorted(int *numbers, int len);
int	*ft_creat_array(char **split, int len);
t_stack	*ft_create_stack_a(int *numbers, int len);
char	*ft_strjoin_2(char *stock, char *arg);
void	ft_putstr(char *str);
int	ft_arraylen(char **split);
void	ft_push(t_stack **src, t_stack **dst, char *msg);
void	ft_swap(t_stack **ptr, char *msg);
void	ft_rotate(t_stack **ptr, char *msg);
void	ft_reverse_rotate(t_stack **ptr, char *msg);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_linked_list_protection(int *array, t_stack *to_check, t_stack *begin);
void	ft_error(char **to_free, char *msg);
void	ft_free_double_pointer(char **s);
void	ft_protection_double_ptr(char **to_check, char *to_free);
void	ft_free_linked_list(t_stack *ptr);
int	ft_strlen(char *s);

#endif