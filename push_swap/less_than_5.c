/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:08:58 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/14 00:11:52 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3_numbers(t_stack **a)
{
	if((*a)->rank == 2)//the begist numver in the begining
	{
		ft_rotate(a, "ra\n");//move it to the end 
		if((*a)->rank == 1)
			ft_swap(a, "sa\n");
		return ;
	}
	if((*a)->rank == 1)//the middle number in the beging
	{
		ft_swap(a, "sa\n");
		if((*a)->rank == 2)
		{
			ft_rotate(a, "ra\n");
			ft_swap(a, "sa\n");
		}
		return ;
	}
	else//the small number is in the begiging
	{
		ft_rotate(a, "ra\n");
		ft_swap(a, "sa\n");
		ft_reverse_rotate(a, "rra\n");
		return ;
	}
}

void	ft_sort_5_numbers(t_stack **a, t_stack **b)
{
	int count;

	count = 0;
	while(*a && count < 2)
	{
		if((*a)->rank == 3 || (*a)->rank == 4)//push big 2 numbers to b
		{
			ft_push(a, b, "pb\n");
			count++;
		}
		ft_rotate(a, "ra\n");
	}
	ft_sort_3_numbers(a);
	ft_push(b, a, "pa\n");
	ft_push(b, a, "pa\n");
	if((*a)->rank == 4)// i wil have some thing like this        10  8  2   4 6
		ft_swap(a, "sa\n");
	ft_rotate(a, "ra\n");
	ft_rotate(a, "ra\n");
}

void	ft_less_than_five(t_stack **a, t_stack **b, int len)
{
	if(len == 2)
		ft_swap(a, "sa\n");
	else if (len == 3)
		ft_sort_3_numbers(a);
	else if (len == 4)
	{
		while(*a)
		{
			if((*a)->rank == 3)
			{
				ft_push(a, b, "pb\n");
				break ;
			}
			ft_rotate(a, "ra\n");
		}
		ft_sort_3_numbers(a);
		ft_push(b, a, "pa\n");
		ft_rotate(a, "ra\n");
		
	}
	else if (len == 5)
		ft_sort_5_numbers(a, b);
	ft_free_linked_list(*a);
	exit (0);
}


