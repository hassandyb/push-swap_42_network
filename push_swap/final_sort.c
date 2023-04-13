/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:13:11 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/13 21:14:49 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_maxnumber_indice(t_stack *list, int len)//create a function  which return the position 
{
	int i;

	i = 0;
	while(list)
	{
		if(list->rank == len - 1)
		{
			return (i);
		}
		list = list->next;
		i++;
	}
	return (i);
}

int ft_normal_case(t_stack **b, t_stack **a,int len, int indice)
{
	t_stack *temp;

	if((*b)->rank == len - 1)
	{
		ft_push(b, a, "pa\n");
		len--;
	}
	else if(indice < len /2)
		ft_rotate(b, "rb\n");
	else  if(indice >= len /2)
		ft_reverse_rotate(b, "rrb\n");
	return len;


}

void ft_push_2_in_right(t_stack **b, t_stack **a, int len)
{
	while(*b)
	{
		if((*b)->rank == len - 2)//len - 2 equal to befor max rank
		{
			ft_push(b, a, "pa\n");
			break;
		}
		else
			ft_rotate(b, "rb\n");		
	}
	while(*b)
	{
		if((*b)->rank == len - 1)// len - 1 is the rank of the max number
		{
			ft_push(b, a, "pa\n");
			break ;
		}
		else
			ft_rotate(b, "rb\n");
	}
	ft_swap(a, "sa\n");
}

void ft_push_2_in_left(t_stack **b, t_stack **a, int len)
{
	while(*b)
	{
		if((*b)->rank == len - 2)// befor max rank;
		{
			ft_push(b, a, "pa\n");
			break ;
		}
		else
			ft_reverse_rotate(b, "rrb\n");
	}
	while(*b)
	{
		if((*b)->rank == len - 1)
		{
			ft_push(b, a, "pa\n");
			break ;
		}
		else
			ft_reverse_rotate(b, "rrb\n");
	}
	ft_swap(a, "sa\n");
}

void ft_final_sort(t_stack **b, t_stack **a, int len)
{
	int indice;
	int befor_max_indice;
	
	while(*b)
	{
		indice = ft_maxnumber_indice(*b, len);
		befor_max_indice = ft_maxnumber_indice(*b, len - 1);
		if(indice < len / 2 && befor_max_indice < len / 2 && befor_max_indice < indice && len > 3)
		{
			ft_push_2_in_right(b, a, len);
			len = len - 2;
		}
		else if(indice > len / 2 && befor_max_indice > len / 2 && befor_max_indice > indice && len > 3)
		{
			ft_push_2_in_left(b, a, len);
			len = len - 2;
		}
		else
			len = ft_normal_case(b, a, len, indice);
	}
}

