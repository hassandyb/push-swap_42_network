/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:03:45 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/17 01:21:38 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_join_args(char **argv)//---
{
	char	*stock;
	int		y;

	stock = NULL;
	y = 1;
	while (argv[y])
	{
		stock = ft_strjoin_2(stock, argv[y]);
		y++;
	}
	y = 0;
	while (stock[y])
	{
		if (stock[y] == '\t')
			stock[y] = ' ';
		y++;
	}
	return (stock);
}

int	ft_atoi(char *s, char **to_free)//---
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	i = 0;
	if (s[0] == '-' || s[0] == '+')
	{
		if (s[0] == '-')
			sign = -1;
		i++;
	}
	if (s[i] == '\0')
		ft_error(to_free, "Error\n");
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10) + s[i] - '0';
		i++;
	}
	result = result * sign;
	if (result < -2147483648 || result > 2147483647)
		ft_error(to_free, "Error\n");
	return (result);
}

void	ft_no_doubles(int *numbers, int len)//---
{
	int	j;
	int	i;
	int	count;

	j = 0;
	while (j < len)
	{
		count = 0;
		i = 0;
		while (i < len)
		{
			if (numbers[j] == numbers[i])
				count++;
			i++;
		}
		if (count > 1)
		{
			write(2, "Error\n", 7);
			exit (0);
		}
		j++;
	}
}



int	*ft_creat_array(char **split, int len)//-----
{
	int	i;
	int	*numbers;

	i = 0;
	numbers = (int *)malloc(len * sizeof(int));
	if (numbers == NULL)
	{
		ft_free_double_pointer(split);
		exit (1);
	}
	while (split[i])
	{
		numbers[i] = ft_atoi(split[i], split);
		i++;
	}
	ft_free_double_pointer(split);
	ft_no_doubles(numbers, len);
	return (numbers);
}
