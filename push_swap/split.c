/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:56:24 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/03/28 18:48:47 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(char *stock)
{
	int	count;
	int	h;

	h = 0;
	while(stock[h] == ' ')
		h++;
	while(stock[h])
	{
		if((stock[h] == ' ' && stock[h + 1] != ' ') || stock[h + 1] == '\0')
			count++;
		h++;
	}
	return (count);
}
char **ft_split(char *stock)
{
	int y;
	int	x;
	int n;
	char **split;
	
	n = ft_count(stock);
	split = (char **)malloc((n + 1) * sizeof(char *));
	if(split == NULL)
	{
		free (stock);
		exit (1);
	}
	x = 0;
	y = 0;
	while(y < n && stock[x] != '\0')
	{
		while(stock[x] = ' ')// here
			x++;
		begin = x;
	}
}

