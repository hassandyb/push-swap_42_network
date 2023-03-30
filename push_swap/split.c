/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:56:24 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/03/30 16:16:33 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(char *stock)
{
	int	count;
	int	h;

	h = 0;
	count = 0;
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

void ft_free_double_pointer(char **s)
{
	int l;

	l = -1;
	while(s[++l])
		free(s[l]);
	free(s);
}

char	*ft_substr(char *stock, int begin, int len, char **split)
{
	char *sub;
	
	int	i;

	i = 0;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if(sub == NULL)
	{
		free (stock);
		ft_free_double_pointer(split);
		exit (1);
	}
	while(len > 0)
	{
		sub[i] = stock[begin];
		i++;
		begin++;
		len--;
	}
	sub[i] = '\0';
	return (sub);
}

void	ft_protection_double_ptr(char **to_check, char *to_free)
{
	if(to_check == NULL)
	{
		free (to_free);
		exit (1);
	}
}

char **ft_split(char *stock)
{
	int y;
	int	x;
	int n;
	int	begin;
	char **split;
	
	n = ft_count(stock);
	split = (char **)malloc((n + 1) * sizeof(char *));
	ft_protection_double_ptr(split, stock);
	x = 0;
	y = 0;
	while(y < n && stock[x] != '\0')
	{
		while(stock[x] == ' ')// here
			x++;
		begin = x;
		while(stock[x] != ' ' && stock[x] != '\0')
			x++;
		split[y] = ft_substr(stock, begin, x - begin, split);// i added stock and split to free it in case of failer allocation
		y++;	
	}
	split[y] = NULL;
	free (stock);
	return (split);
}
