/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:19:20 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/16 20:47:27 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*why + 1 + 1 ===>  +1 for the space +1 for '\0'*/

void	ft_protection(char *to_check, char *to_free)
{
	if (to_check == NULL)
	{
		free(to_free);
		exit (1);
	}
}

char	*ft_strjoin_2(char *stock, char *arg)//---
{
	char	*result;
	int		i;
	int		j;

	j = 0;
	i = -1;
	if (stock == NULL)
	{
		stock = (char *)malloc(sizeof(char));
		if (stock == NULL)
			exit (1);
		stock[0] = '\0';
	}
	result = (char *)malloc((ft_strlen(stock) + ft_strlen(arg) + 1 + 1));
	ft_protection(result, stock);
	while (stock[++i])
		result[i] = stock[i];
	while (arg[j])
		result[i++] = arg[j++];
	result[i] = ' ';
	result[++i] = '\0';
	free (stock);
	return (result);
}

void	ft_putstr(char *str)//---
{
	int	i;

	if (str == NULL)
		return ;
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

int	ft_arraylen(char **split)//---
{
	int	l;

	l = 0;
	while (split[l])
		l++;
	return (l);
}

int	ft_strlen(char *s)
{
	int	k;

	k = 0;
	while (s[k])
		k++;
	return (k);
}