/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:01:43 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/05 17:34:52 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ft_push(t_stack **src, t_stack **dst, char *msg)
{
	if(*src == NULL)
		return;
	t_stack *new_src;
	
	new_src = (*src)->next;

	(*src)->next = *dst;
	*dst = *src;
	*src = new_src;
	ft_putstr(msg);
}

void ft_swap(t_stack **ptr, char *msg)
{
	t_stack *swap;
	
	if(*ptr == NULL || (*ptr)->next)
		return;
	swap = (*ptr)->next;

	(*ptr)->next = (*ptr)->next->next;
	swap->next = (*ptr);
	(*ptr) = swap;
	ft_putstr(msg);
}

void ft_rotate(t_stack **ptr, char *msg)
{
	t_stack *begin;
	t_stack *temp;
	if(*ptr == NULL || (*ptr)->next)
		return ;
	begin = (*ptr)->next;
	temp = (*ptr);



	begin = (*ptr)->next;
	while(temp)
	{
		if(temp->next == NULL)
			break ;
		else
			temp = temp->next;
	}
	temp->next = *ptr;
	(*ptr)->next = NULL;
	(*ptr) = begin;
	ft_putstr(msg);

}

void ft_reverse_rotate(t_stack **ptr, char *msg)
{
	t_stack *begin;
	t_stack *befor_last;
	t_stack *temp;
	
	if(*ptr == NULL || (*ptr)->next == NULL)
		return ;
	begin = *ptr;
	while(ptr)
	{
		if((*ptr)->next->next == NULL)
		{
			befor_last = (*ptr);
			break ;
		}
		(*ptr) = (*ptr)->next;
	}
	(*ptr) = (*ptr)->next;

	(*ptr)->next = begin;
	befor_last->next = NULL;
	ft_putstr(msg);
	
}