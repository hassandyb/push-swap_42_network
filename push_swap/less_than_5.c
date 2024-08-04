/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:08:58 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/15 12:39:19 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3_numbers(t_stack **a, int min_rank)
{
	if ((*a)->rank == min_rank + 2)
	{
		ft_rotate(a, "ra\n");
		if ((*a)->rank == min_rank + 1)
			ft_swap(a, "sa\n");
	}
	else if ((*a)->rank == min_rank + 1)
	{
		ft_swap(a, "sa\n");
		if ((*a)->rank == min_rank + 2)
		{
			ft_rotate(a, "ra\n");
			ft_swap(a, "sa\n");
		}
	}
	else if ((*a)->rank == min_rank)
	{
		if ((*a)->next->rank == min_rank + 1)
			return ;
		ft_rotate(a, "ra\n");
		ft_swap(a, "sa\n");
		ft_reverse_rotate(a, "rra\n");
	}
}

void	ft_sort_4_numbers(t_stack **a, t_stack **b)
{
	while (*a)
	{
		if ((*a)->rank == 0)
		{
			ft_push(a, b, "pb\n");
			break ;
		}
		else
			ft_rotate(a, "ra\n");
	}
	ft_sort_3_numbers(a, 1);
	ft_push(b, a, "pa\n");
}

void	ft_sort_5_numbers(t_stack **a, t_stack **b)
{
	int	count;

	count = 0;
	while (count < 2)
	{
		if ((*a)->rank < 2)
		{
			ft_push(a, b, "pb\n");
			count++;
		}
		else
			ft_rotate(a, "ra\n");
	}
	ft_sort_3_numbers(a, 2);
	ft_push(b, a, "pa\n");
	ft_push(b, a, "pa\n");
	if ((*a)->rank == 1)
		ft_swap(a, "sa\n");
}

void	ft_less_than_five(t_stack **a, t_stack **b, int len)
{
	int	count;

	count = 0;
	if (len == 2)
		ft_swap(a, "sa\n");
	else if (len == 3)
		ft_sort_3_numbers(a, 0);
	else if (len == 4)
		ft_sort_4_numbers(a, b);
	else if (len == 5)
		ft_sort_5_numbers(a, b);
	ft_free_linked_list(*a);
	exit (0);
}
