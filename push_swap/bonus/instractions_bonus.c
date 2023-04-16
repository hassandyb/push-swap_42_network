/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:01:43 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/16 17:16:14 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_push(t_stack **src, t_stack **dst, char *msg)
{
	t_stack	*src_begin;

	if (*src == NULL || src == NULL)
		return ;
	src_begin = *src;
	*src = (*src)->next;
	src_begin->next = *dst;
	*dst = src_begin;
	ft_putstr(msg);
}

void	ft_swap(t_stack **ptr, char *msg)
{
	t_stack	*swap;

	if (*ptr == NULL || (*ptr)->next == NULL)
		return ;
	swap = (*ptr)->next;
	(*ptr)->next = (*ptr)->next->next;
	swap->next = (*ptr);
	(*ptr) = swap;
	if (msg)
		ft_putstr(msg);
}

void	ft_rotate(t_stack **ptr, char *msg)
{
	t_stack	*begin;
	t_stack	*temp;

	if (ptr == NULL || *ptr == NULL || (*ptr)->next == NULL)
		return ;
	begin = (*ptr)->next;
	temp = (*ptr);
	while (temp)
	{
		if (temp->next == NULL)
			break ;
		else
			temp = temp->next;
	}
	temp->next = *ptr;
	(*ptr)->next = NULL;
	(*ptr) = begin;
	if (msg)
		ft_putstr(msg);
}

void	ft_reverse_rotate(t_stack **ptr, char *msg)
{
	t_stack	*begin;
	t_stack	*befor_last;

	befor_last = NULL;
	if (*ptr == NULL || (*ptr)->next == NULL)
		return ;
	begin = *ptr;
	while (*ptr)
	{
		if ((*ptr)->next->next == NULL)
		{
			befor_last = (*ptr);
			break ;
		}
		(*ptr) = (*ptr)->next;
	}
	(*ptr) = (*ptr)->next;
	(*ptr)->next = begin;
	befor_last->next = NULL;
	if (msg)
		ft_putstr(msg);
}
