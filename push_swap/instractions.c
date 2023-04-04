/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:01:43 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/04 14:26:17 by hed-dyb          ###   ########.fr       */
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