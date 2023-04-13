/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:11:33 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/13 21:21:09 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ft_protection(char *to_check, char *to_free)
{
	if(to_check == NULL)	
	{
		free(to_free);
		exit (1);
	}
}

void ft_error(char **to_free, char *msg)
{
	ft_putstr(msg);
	ft_free_double_pointer(to_free);
	exit(1);
}

void ft_free_double_pointer(char **s)
{
	int l;

	l = -1;
	while(s[++l])
		free(s[l]);
	free(s);
}

void	ft_protection_double_ptr(char **to_check, char *to_free)
{
	if(to_check == NULL)
	{
		free (to_free);
		exit (1);
	}
}

void	ft_free_linked_list(t_stack *ptr)
{
	t_stack *node_saver;
	
	while(ptr)
	{
		node_saver = ptr;
		ptr = ptr->next;
		free (node_saver);
	}
}
