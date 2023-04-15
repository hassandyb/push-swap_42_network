/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:03:58 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/15 12:17:58 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_stack **a, t_stack **b)
{
	if (*a == NULL || *b == NULL || (*a)->next == NULL || (*b)->next == NULL)
		return ;
	ft_rotate(a, NULL);
	ft_rotate(b, NULL);
	ft_putstr("rr\n");
}

void	ft_ss(t_stack **a, t_stack **b)
{
	if (*a == NULL || *b == NULL || (*a)->next == NULL || (*b)->next == NULL)
		return ;
	ft_swap(a, NULL);
	ft_swap(b, NULL);
	ft_putstr("ss\n");
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	if (*a == NULL || *b == NULL || (*a)->next == NULL || (*b)->next == NULL)
		return ;
	ft_reverse_rotate(a, NULL);
	ft_reverse_rotate(b, NULL);
	ft_putstr("rrr\n");
}

void	ft_linked_list_protection(int *array, t_stack *to_check, t_stack *begin)
{
	if (to_check == NULL)
	{
		free (array);
		ft_free_linked_list(begin);
		exit (1);
	}
}
