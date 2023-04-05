/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:01:43 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/05 12:58:55 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ft_push(t_stack **src, t_stack **dst, char *msg)
{
	if(src == NULL || *src == NULL)
		return;
	t_stack *new_src;
	
	new_src = (*src)->next;

	(*src)->next = *dst;
	*dst = *src;
	*src = new_src;
	ft_putstr(msg);
	printf("\n"); //delete it later
}

void ft_swap(t_stack **ptr, char *msg)
{
	t_stack *swap;
	
	if(ptr == NULL && *ptr == NULL)
		return;
	swap = (*ptr)->next;
	if(swap == NULL)
		return ;
	(*ptr)->next = (*ptr)->next->next;
	swap->next = (*ptr);
	(*ptr) = swap;
	ft_putstr(msg);
	printf("\n"); //delete it later
}