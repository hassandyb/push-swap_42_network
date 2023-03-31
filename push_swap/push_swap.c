/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:35:50 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/03/31 15:02:28 by hed-dyb          ###   ########.fr       */
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
	
	y = 1;
	while(argv[y])
	{
		x = 0;	
		while(argv[y][x] != '\0' && (argv[y][x] == ' ' || argv[y][x] == '\t')) 
			x++;
		if(argv[y][x] == '\0' || argv[y][0] == '\0')// for ar arg full of spaces and tabs or an empty arg == \0
		{
			write(2, "Error :\nEmpty arg or arg full of spaces and tabs!" , 50);
			exit(0); 
		}
		y++;
	}
}

void	ft_check2(char **argv)
{
	int	y;
	int	x;

	y = 1;
	while(argv[y])
	{
		x = 0;
		while(argv[y][x])
		{
			if(argv[y][x] != ' ' && argv[y][x] != '\t' && argv[y][x] != '-'
				&& argv[y][x] != '+' && (argv[y][x] < '0' || argv[y][x] > '9'))
			{
				write(2, "Error :\nCheck args!", 20);
				exit(0); 
			}
			if((argv[y][x] == '-' || argv[y][x] == '+') && (argv[y][x+1] == ' ' 
				|| argv[y][x+1] == '\t'))
			{
				write(2, "Error :\nTab or space after + or -!", 35);
				exit(0); 
			}
			x++;
		}
		y++;
	}
}

void ft_check3(char **argv)
{
	int y;
	int x;

	y = 1;
	while(argv[y])
	{
		x = 0;
		while(argv[y][x])
		{
			if((argv[y][x] == '-' || argv[y][x] == '+') && (argv[y][x+1] == '-' || argv[y][x+1] == '+'))
			{
				write(1, "Error :\nYou have -- ++ -+ or +-!", 33);
				exit (0);
			}
			x++;
		}
		y++;
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
//--------------------------------------
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
	int result;
	
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
	{
		write(2 , "Error :\nArg containing - or + only!",36);
		ft_free_double_pointer(to_free);
		exit(1);
	}
	while(s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10) + s[i] - '0';
		i++;
	}
	return (result * sign);
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
	write(2, "Error :\nArgs are already sorted!",33);
	free(numbers);
	exit (1);
}

int main (int argc, char **argv)
{
	char 	*stock;
	char 	**split;
	int		*numbers;
	int		len;
	
	if(argc == 1)
		exit (0);
	ft_check(argv);
	ft_check2(argv);
	ft_check3(argv);
	stock = ft_join_args(argv);
	//------
	split = ft_split(stock);
	//----
	len = ft_arraylen(split);
	numbers = ft_creat_array(split, len);
	ft_no_doubles(numbers, len);
	ft_not_sorted(numbers, len);
	
	

	
	int j = -1;
	while(++j < len)
		printf("%d  |", numbers[j]);
		
	printf("\n\n");
	
	
	printf("\n\n");
	j = -1;
	while(++j < len)
		printf("%d  )", numbers[j]);

}

//you need to handler the case -- and ++ -+ +-....
//You have -- ++ -+ or +-!
// go to atoi and handler the error text