/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:56:26 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/14 23:03:53 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_linked_list_protection(int *array, t_stack *to_check, t_stack *begin)
{
	if (to_check == NULL)
	{
		free (array);
		ft_free_linked_list(begin);
		exit (1);
	}
}

t_stack	*ft_create_stack_a(int *numbers, int len)
{
	t_stack	*old;
	t_stack	*new;
	t_stack	*begin;
	int		i;

	i = 0;
	begin = malloc(sizeof(t_stack));
	ft_linked_list_protection(numbers, begin, begin);
	begin->rank = -1;
	begin->data = numbers[i++];
	begin->next = NULL;
	old = begin;
	while (i < len)
	{
		new = malloc(sizeof(t_stack));
		ft_linked_list_protection(numbers, new, begin);
		new->rank = -1;
		new->data = numbers[i];
		new->next = NULL;
		old->next = new;
		old = new;
		i++;
	}
	return (begin);
}

void	ft_add_rank(t_stack *ptr, int *numbers, int len)
{
	int	j;
	int	i;

	j = 0;
	while (ptr)
	{
		i = 0;
		while (i < len)
		{
			if (ptr->data == numbers[i])
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

int	ft_wich_chunk(int len)
{
	int	chunk;

	if (len >= 6 && len <= 100)
		chunk = len / 5;
	else
		chunk = len / 10;
	return (chunk);
}

void	ft_sort_with_chunk(t_stack **a, t_stack **b,int len)
{
	int	chunk;
	int	count;
	int	indice;

	chunk = ft_wich_chunk(len);
	indice = 1;
	while (*a != NULL)
	{
		count = 0;
		while (*a != NULL && count < chunk)
		{
			if ((*a)->rank < (chunk * indice))
			{
				ft_push(a, b, "pb\n");
				if ((*b)->rank >= (chunk * indice) - (chunk  / 2))
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
