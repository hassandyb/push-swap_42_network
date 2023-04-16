/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:51:18 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/16 22:01:19 by hed-dyb          ###   ########.fr       */
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

void	ft_read()
{
	char *line;
	int y = read(0, line, 1024);
	line = get_next_line(0);
	while(y > 0)
	{
		line = get_next_line(0);
		puts(line);
	}
}
#include <fcntl.h>

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
	int fd = open("/Users/hed-dyb/Desktop/push_swap/bonus/aaaa", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	ft_read();
	ft_free_linked_list(stack_a);
}
