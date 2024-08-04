/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:19:20 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/15 12:16:45 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*why + 1 + 1 ===>  +1 for the space +1 for '\0'*/
char	*ft_strjoin(char *stock, char *arg)
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

int	ft_strlen(char *s)
{
	int	k;

	k = 0;
	while (s[k])
		k++;
	return (k);
}

void	ft_putstr(char *str)
{
	int	i;

	if (str == NULL)
		return ;
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

void	ft_sort_array(int *numbers, int len)
{
	int	i;
	int	swap;

	i = 0;
	while (i < len - 1)
	{
		if (numbers[i] > numbers[i + 1])
		{
			swap = numbers[i];
			numbers[i] = numbers[i + 1];
			numbers[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
}

int	ft_arraylen(char **split)
{
	int	l;

	l = 0;
	while (split[l])
		l++;
	return (l);
}
