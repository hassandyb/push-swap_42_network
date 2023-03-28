/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:35:50 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/03/28 17:30:56 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//chanks algo
//./push-swap aaa aaa aaa aaa aaaa  argc = 6;

// spaces : argc - 2;
// back slash zero :+ 1 ;

void ft_check(char **argv)
{
	int y;
	int x;
	
	y = 0;
	while(argv[++y])
	{
		x = 0;	
		while(argv[y][x] != '\0' && (argv[y][x] == ' ' || argv[y][x] == '\t')) 
			x++;
		if(argv[y][x] == '\0' || argv[y][0] == '\0')// for ar arg full of spaces and tabs or an empty arg == \0
		{
			write(2, "Error!", 7);
			exit(0); 
		}
	}
}

void	ft_check2(char **argv)
{
	int	y;
	int	x;

	y = 0;
	while(argv[++y])
	{
		x = -1;
		while(argv[y][++x])
		{
			if(argv[y][x] != ' ' && argv[y][x] != '\t' && argv[y][x] != '-' && argv[y][x] != '+' && (argv[y][x] < '0' || argv[y][x] > '9'))
			{
				write(2, "Error!", 7);
				exit(0); 
			}
			if((argv[y][x] == '-' || argv[y][x] == '+') && (argv[y][x+1] == ' ' || argv[y][x+1] == '\t'))
			{
				write(2, "Error!", 7);
				exit(0); 
			}
		}
	}
}

int	ft_strlen(char *s)
{
	int	k;
	
	k = 0;
	while(s[k])
		k++;
	return k;
}

void ft_protection(char *to_check, char *to_free)
{
	if(to_check == NULL)	
	{
		free(to_free);
		exit (1);
	}
}

char	*ft_strjoin(char *stock, char *arg)
{
	char *result;
	int i;
	int	j;
	
	j = 0;
	i = -1;
	if(stock == NULL)
	{
		stock = (char *)malloc(sizeof(char));
		if(stock == NULL)
			exit (1);
		stock[0] = '\0';
	}
	result = (char *)malloc((ft_strlen(stock) + ft_strlen(arg) + 1 + 1));//+1 for the space +1 for '\0'
	ft_protection(result, stock);
	while(stock[++i])
		result[i] = stock[i];
	while(arg[j])
		result[i++] = arg[j++];
	result[i] = ' ';
	result[++i] = '\0';
	free (stock);
	return (result);
}

char	*ft_join_args(char **argv)
{
	char	*stock;
	int		y;

	stock = NULL;
	y = 1;
	while(argv[y])
	{
		stock = ft_strjoin(stock, argv[y]);
		y++;
	}
	y = 0;
	while(stock[y])
	{
		if(stock[y] == '\t')
			stock[y] = ' ';
		y++;
	}
	return (stock);
}

int main (int argc, char **argv)
{
	char *stock;
	char **numbers;
	if(argc == 1)
		exit (0);
	ft_check(argv);
	ft_check2(argv);
	stock = ft_join_args(argv);
	// numbers = ft_split(stock);
	// printf("%s", stock)
}