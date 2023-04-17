/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:35:50 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/17 13:33:53 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check1(char **argv)
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
			write(2, "Error :\nEmpty arg or arg full of spaces and tabs!", 50);
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
	while (argv[y])
	{
		x = 0;
		while (argv[y][x])
		{
			if (argv[y][x] != ' ' && argv[y][x] != '\t' && argv[y][x] != '-'
				&& argv[y][x] != '+' && (argv[y][x] < '0' || argv[y][x] > '9'))
			{
				write(2, "Error :\nCheck args!", 20);
				exit(0);
			}
			if ((argv[y][x] == '-' || argv[y][x] == '+') &&
				(argv[y][x + 1] == ' ' || argv[y][x + 1] == '\t'))
			{
				write(2, "Error :\nTab or space after + or -!", 35);
				exit(0);
			}
			x++;
		}
		y++;
	}
}

void	ft_check3(char **argv)
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
				write(1, "Error :\nYou have -- ++ -+ or +-!", 33);
				exit (0);
			}
			if ((argv[y][x] >= '0' && argv[y][x] <= '9') && (argv[y][x + 1] ==
				'+' || argv[y][x + 1] == '-'))
			{
				write(1, "Error :\nYou have + or - after a number!", 40);
				exit (0);
			}
			x++;
		}
		y++;
	}
}

void	ft_check_args(int argc, char **argv)
{
	if (argc == 1)
		exit (0);
	ft_check1(argv);
	ft_check2(argv);
	ft_check3(argv);
}

int	main(int argc, char **argv)
{
	char	**split;
	int		*numbers;
	int		len;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	ft_check_args(argc, argv);
	split = ft_split(ft_join_args(argv));
	len = ft_arraylen(split);
	numbers = ft_creat_array(split, len);
	stack_a = ft_create_stack_a(numbers, len);
	ft_sort_array(numbers, len);
	ft_add_rank(stack_a, numbers, len);
	if (len <= 5)
		ft_less_than_five(&stack_a, &stack_b, len);
	ft_sort_with_chunk(&stack_a, &stack_b, len);
	ft_final_sort(&stack_b, &stack_a, len);
	ft_free_linked_list(stack_a);
}
