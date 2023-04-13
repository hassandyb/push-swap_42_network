/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_and_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:07:37 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/13 17:15:58 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void ft_add_rank(t_stack *ptr, int *numbers, int len)
{
	int j;
	int i;
	j = 0;
	while(ptr)
	{
		i = 0;
		while(i < len)
		{
			if(ptr->data == numbers[i])
			{
				ptr->rank = i;
				break ;
			}
			i++;
		}
		ptr = ptr->next;
	}
	free(numbers);
}
// -------------------------------
int ft_wich_chunk(int len)
{
	int chunk;

	if(len >= 6 && len <= 100)
		chunk = len / 5;
	else
		chunk = len / 11;
	return (chunk);
}


void ft_sort_with_chunk(t_stack **a, t_stack **b,int len)
{
	int chunk;
	int count;
	int indice;
	
	chunk = ft_wich_chunk(len);
	indice = 1;
	while(*a != NULL)
	{
		count = 0;
		while( *a != NULL && count < chunk)
		{
			if((*a)->rank < (chunk * indice))//we try to ing the numbers of our chunk
			{
				ft_push(a, b, "pb\n");
				if((*b)->rank >= (chunk * indice) - (chunk  / 2)) // we split the chunk numbers big at end small at the beginig - while to get the chank numbers we split them ==>big numbers -->rorate ->we to the end | and we keep small numbers in the beging of our linkedlist
				{
					if (*a && (*a)->rank >= (chunk * indice))
						ft_rr(a, b);
					else
						ft_rotate(b, "rb\n");
				}
				count++;
			}
			else
				ft_rotate(a, "ra\n");
		}
		indice++;
	}
}
//create a function  which return the position 
int ft_maxnumber_indice(t_stack *list, int len)
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
//---------
