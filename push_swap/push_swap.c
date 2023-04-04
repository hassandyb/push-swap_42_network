/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:35:50 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/04 14:26:11 by hed-dyb          ###   ########.fr       */
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

//--------------------------

void	ft_free_linked_list(t_stack *ptr)
{
	t_stack *next_node_saver;
	
	while(ptr)
	{
		ptr->next = next_node_saver;
		free (ptr);
		ptr = next_node_saver;
	}

}

void ft_linked_list_protection(int *array, t_stack *to_check, t_stack *begin)
{
	if(to_check == NULL)
	{
		free (array);
		ft_free_linked_list(begin);
		exit (1);
	}
}

t_stack	*ft_create_stack_a(int *numbers, int len)
{
	t_stack *old;
	t_stack *new;
	t_stack *begin;
	int i;
	
	i = 0;
	begin = malloc(sizeof(t_stack));
	ft_linked_list_protection(numbers, begin, begin);
	begin->data = numbers[i];
	begin->next = NULL;
	old = begin;
	i++;
	while(i<len)
	{
		new = malloc(sizeof(t_stack));
		ft_linked_list_protection(numbers, new, begin);
		new->data = numbers[i];
		new->next = NULL;
		old->next = new;
		old = new;
		i++;
	}
	free (numbers);
	return (begin);
}

//--------  for tests only --------
void print_stack(t_stack *stack_a)
{
	if(stack_a == NULL)
		printf("NUll pointer.\n");
	while(stack_a)
	{
		printf("%d  ", stack_a->data);
		stack_a = stack_a->next;
	}
	printf("\n");
}









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


	
	


	
	
}

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





