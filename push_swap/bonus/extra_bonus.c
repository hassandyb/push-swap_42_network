/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:18:21 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/16 15:18:42 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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