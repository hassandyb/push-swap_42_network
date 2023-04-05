/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:23:08 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/05 17:29:32 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_arraylen(char **split)
{
	int	l;

	l = 0;
	while(split[l])
		l++;
	return (l);
}

int ft_atoi(char *s, char **to_free)
{
	int i;
	int sign;
	long result;
	
	result = 0;
	sign = 1;
	i = 0;
	if(s[0] == '-' || s[0] == '+')
	{
		if(s[0] == '-')
			sign = -1;
		i++;
	}
	if (s[i] == '\0')// in case you have - or + only
		ft_error(to_free, "Error :\nArg containing - or + only!");
	while(s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10) + s[i] - '0';
		i++;
	}
	result = result * sign;
	if(result < -2147483648 || result > 2147483647)
		ft_error(to_free, "Error :\nInt coudn't hold a number!");
	return (result);
}

int *ft_creat_array(char **split, int len)
{
	int	i;
	int	*numbers;

	i = 0;
	numbers = (int *)malloc(len * sizeof(int));
	if(numbers == NULL)
	{
		ft_free_double_pointer(split);
		exit (1);
	}
	while(split[i])
	{
		numbers[i] = ft_atoi(split[i], split);
		i++;
	}
	ft_free_double_pointer(split);
	return (numbers);
}

void	ft_no_doubles(int *numbers, int len)
{
	int j;
	int	i;
	int count;

	
	j = 0;
	while(j < len)
	{
		count = 0;
		i = 0;
		while(i < len)
		{
			if(numbers[j] == numbers[i])
				count++;
			i++;
		}
		if(count > 1)
		{
			write(2, "Error : \nDouble number!", 24);
			exit (0);
		}
		j++;
	}
}

void	ft_not_sorted(int *numbers, int len)
{
	int i = 0;
	while(i < len - 1)
	{
		if(numbers[i] > numbers[i+1])
			return;
		i++;
	}
	write(2, "Error :\nNumbers are already sorted - or one number !",53);
	free(numbers);
	exit (1);
}