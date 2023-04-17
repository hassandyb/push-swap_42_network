/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:51:18 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/17 01:51:26 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"



void	ft_check1(char **argv)//----
{
	int	y;
	int	x;

	y = 1;
	while (argv[y])
	{
		x = 0;
		while (argv[y][x] != '\0' && (argv[y][x] == ' ' || argv[y][x] == '\t'))
			x++;
		if (argv[y][x] == '\0' || argv[y][0] == '\0')
		{
			write(2, "Error\n", 7);
			exit(0);
		}
		y++;
	}
}

void	ft_check2(char **argv)//--
{
	int	y;
	int	x;

	y = 1;
	while (argv[y])
	{
		x = 0;
		while (argv[y][x])
		{
			if (argv[y][x] != ' ' && argv[y][x] != '\t' && argv[y][x] != '-'
				&& argv[y][x] != '+' && (argv[y][x] < '0' || argv[y][x] > '9'))
			{
				write(2, "Error\n", 7);
				exit(0);
			}
			if ((argv[y][x] == '-' || argv[y][x] == '+') &&
				(argv[y][x + 1] == ' ' || argv[y][x + 1] == '\t'))
			{
				write(2, "Error\n", 7);
				exit(0);
			}
			x++;
		}
		y++;
	}
}

void	ft_check3(char **argv)//----
{
	int	y;
	int	x;

	y = 1;
	while (argv[y])
	{
		x = 0;
		while (argv[y][x])
		{
			if ((argv[y][x] == '-' || argv[y][x] == '+') && (argv[y][x + 1] ==
				'-' || argv[y][x + 1] == '+'))
			{
				write(1, "Error\n", 7);
				exit (0);
			}
			if ((argv[y][x] >= '0' && argv[y][x] <= '9') && (argv[y][x + 1] ==
				'+' || argv[y][x + 1] == '-'))
			{
				write(1, "Error\n", 7);
				exit (0);
			}
			x++;
		}
		y++;
	}
}

void	ft_check_args(int argc, char **argv)//---
{
	if (argc == 1)
		exit (0);
	ft_check1(argv);
	ft_check2(argv);
	ft_check3(argv);
}


int	ft_check_sort(t_stack *a)//---
{
	
	while(a != NULL && a->next != NULL)
	{
		if(a->data > a->next->data)
			return 0;
	}
	return (1);
}

void ft_result(t_stack *a, t_stack *b, char *msg)
{
	ft_free_linked_list(a);
	ft_free_linked_list(b);
	ft_putstr(msg);
	exit (0);
}

int ft_compare(char *line, char *instraction)
{
	int	i;

	i = 0;
	if(line == NULL || instraction == NULL)
		return (0);
	while(line[i] && instraction[i])
	{
		if(line[i] != instraction[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_execute(char *line, t_stack **a, t_stack **b)
{
	if(ft_compare(line, "ra\n") == 1)
		ft_rotate(a);
	else if(ft_compare(line, "rb\n") == 1)
		ft_rotate(b);	
	else if(ft_compare(line, "sa\n") == 1)
		ft_swap(a);
	else if(ft_compare(line, "sb\n") == 1)
		ft_swap(b);
	else if(ft_compare(line, "rra\n") == 1)
		ft_reverse_rotate(a);
	else if(ft_compare(line, "rrb\n") == 1)
		ft_reverse_rotate(b);
	else if(ft_compare(line, "pa\n") == 1)
		ft_push(b, a);
	else if(ft_compare(line, "pb\n") == 1)
		ft_push(a, b);
	else if(ft_compare(line, "rr\n") == 1)
		ft_rr(a, b);
	else if(ft_compare(line, "ss\n") == 1)
		ft_ss(a, b);
	else if(ft_compare(line, "rrr\n") == 1)
		ft_rrr(a, b);
	else
		ft_result(*a, *b, "ko\n");
}

void	ft_read(t_stack **a, t_stack **b)
{
	char *line;
	
	line = get_next_line(0);
	if(*b == NULL && ft_check_sort(*a) == 1)
		ft_result(*a, *b, "ok\n");
	else
		ft_result(*a, *b, "ko\n");
	
	while(line)
	{
		// printf("{%s}", line);
		ft_execute(line, a, b);
		line = get_next_line(0);
	}
	if(*b == NULL && ft_check_sort(*a) == 1)
		ft_result(*a, *b, "ok\n");
	else
		ft_result(*a, *b, "ko\n");
		
}

//a sorted  and b is empty ==>desplay ok\n =>exit
//else desplay ko\n and exit
int	main(int argc, char **argv)
{
	char	**split;
	int		*numbers;
	int		len;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	ft_check_args(argc, argv);
	split = ft_split(ft_join_args(argv));
	len = ft_arraylen(split);
	numbers = ft_creat_array(split, len);
	stack_a = ft_create_stack_a(numbers, len);
	ft_read(&stack_a, &stack_b);
}
