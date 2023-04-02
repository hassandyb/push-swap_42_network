/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:35:50 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/02 13:19:41 by hed-dyb          ###   ########.fr       */
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

void ft_putstr(char *str)
{
	int i;
	
	i = -1;
	while(str[++i])
		write(1, &str[i], 1);
}
void ft_error(char **to_free, char *msg)
{
	ft_putstr(msg);
	ft_free_double_pointer(to_free);
	exit(1);
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
	write(2, "Error :\nArgs are already sorted!",33);
	free(numbers);
	exit (1);
}
//-----------------------------------------
t_stack *ft_create_node(int data)
{
	t_stack *cur;
	
	cur = malloc(sizeof(t_stack));
	cur->data = data;
	cur->next = NULL;
	return (cur);
}

t_stack	*ft_create_stack_a(int *numbers, int len)
{
	t_stack *node;
	t_stack *begin;
	t_stack *new;
	int i;

	i = 0;
	node = ft_create_node(numbers[i++]);
	begin = node;
	while(i < len)
	{
		new = ft_create_node(numbers[i]);
		node->next = new;
		node = new;
		i++;
	}
	return (begin);
}





//--------  for tests only --------
void print_stack(t_stack *stack_a)
{
	while(stack_a)
	{
		printf("%d\n", stack_a->data);
		stack_a = stack_a->next;
	}
}
// -------------------------------

int main (int argc, char **argv)
{
	char 	*stock;
	char 	**split;
	int		*numbers;
	int		len;
	t_stack *stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
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
	//-----
	stack_a = ft_create_stack_a(numbers, len);

	
	
	print_stack(stack_a);
	// ft_push(&stack_a, &stack_b, "pb");

	
	
}

// go atoi hander max int nad min int

// sa = swap stack a = swap tow first data;   =>  3 8 4 6 =>   8 3  4 6
// same for sb;


// ra and rb  rotate
// make the first data begin the last but be curfeu to the order  2 4 6 7 => 4 6 7 2

// rra rrb  reverce rotate
//  make the last becom etne first             2 4 6 7 => 7 2 4 6

//  pa pb push to a --  push to b
// stack a : 2  4 6 7 
// stack b null in the begining

// pb push to be

// stack a :   4 6 7 
// stack b : 2(next = null)(we moved 2 from a to be -- next of b satays null)

// pb

// stack a : 6 7 
// stack b : 4 2  (we moved the first again (4) t b -- next of 4 ->2 -- 2 stiil points to null)....

// pa

// stack a : 4 6 7 
// stack b :  2





