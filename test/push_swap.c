/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:35:50 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/13 18:50:07 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//chanks algo
//./push-swap aaa aaa aaa aaa aaaa  argc = 6;

// spaces : argc - 2;
// back slash zero :+ 1 ;



void ft_check1(char **argv)
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
			if((argv[y][x] >= '0' && argv[y][x] <= '9') && (argv[y][x+1] == '+' || argv[y][x+1] == '-'))
			{
				write(1, "Error :\nYou have + or - directly after a number!", 49);
				exit (0);
			}

			x++;
		}
		y++;
	}
}

void	ft_check_args(int argc, char **argv)
{
	if(argc == 1)
			exit (0);
	ft_check1(argv);
	ft_check2(argv);
	ft_check3(argv);
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
	t_stack *node_saver;
	
	while(ptr)
	{
		node_saver = ptr;
		ptr = ptr->next;
		free (node_saver);
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
	begin->rank = -1;
	begin->data = numbers[i++];
	begin->next = NULL;
	old = begin;
	while(i<len)
	{
		new = malloc(sizeof(t_stack));
		ft_linked_list_protection(numbers, new, begin);
		new->rank = -1;
		new->data = numbers[i];
		new->next = NULL;
		old->next = new;
		old = new;
		i++;
	}
	return (begin);
}

//--------  for tests only --------
void print_stack(t_stack *list)
{
	if(list == NULL)
	{
		printf("NUll\n");
		return;
	}
		
	while(list)
	{
		printf("%d      ", list->data);
		list = list->next;
	}
	printf("\n");
}

void print_stack_(t_stack *list)
{
	if(list == NULL)
	{
		printf("NUll\n");
		return;
	}
		
	while(list)
	{
		printf("%d->%d      ", list->data, list->rank);
		list = list->next;
	}
	printf("\n");
}

void print_array(int *array, int len)
{
	int i = 0;
	if(len == 0)
		printf("len equal to zero!");
	while(i < len)
	{
		printf("%d  ", array[i]);
		i++;
	}
	printf("\n");
}
//-------------------------------
void ft_push_2_in_right(t_stack **b, t_stack **a, int len)
{
	while(*b)
	{
		if((*b)->rank == len - 2)//len - 2 equal to befor max rank
		{
			ft_push(b, a, "pa\n");
			break;
		}
		else
			ft_rotate(b, "rb\n");		
	}
	while(*b)
	{
		if((*b)->rank == len - 1)// len - 1 is the rank of the max number
		{
			ft_push(b, a, "pa\n");
			break ;
		}
		else
			ft_rotate(b, "rb\n");
	}
	ft_swap(a, "sa\n");
}

void ft_push_2_in_left(t_stack **b, t_stack **a, int len)
{
	while(*b)
	{
		if((*b)->rank == len - 2)// befor max rank;
		{
			ft_push(b, a, "pa\n");
			break ;
		}
		else
			ft_reverse_rotate(b, "rrb\n");
	}
	while(*b)
	{
		if((*b)->rank == len - 1)
		{
			ft_push(b, a, "pa\n");
			break ;
		}
		else
			ft_reverse_rotate(b, "rrb\n");
	}
	ft_swap(a, "sa\n");
}

void ft_final_sort(t_stack **b, t_stack **a, int len)
{

	int indice;
	int befor_max_indice;
	
		// printf(">%d   |", *b);
	while(*b)
	{
		// printf("%d   |", len);
		indice = ft_maxnumber_indice(*b, len);
		befor_max_indice = ft_maxnumber_indice(*b, len - 1);
		if(indice < len / 2 && befor_max_indice < len / 2 && befor_max_indice < indice && len > 3)
		{
			ft_push_2_in_right(b, a, len);
			len = len - 2;
		}
		else if(indice > len / 2 && befor_max_indice > len / 2 && befor_max_indice > indice && len > 3)
		{
			ft_push_2_in_left(b, a, len);
			len = len - 2;
		}
		else
			len = ft_normal_case(b, a, len, indice);
	}
}

void ft_leaks(){system("leaks push_swap");}

int main (int argc, char **argv)
{
	atexit (ft_leaks);
	char 	*stock;
	char 	**split;
	int		*numbers;
	int		len;
	t_stack *stack_a;
	t_stack	*stack_b;
	int indice;
	int befor_max_indice;

	stack_a = NULL;
	stack_b = NULL;
	ft_check_args(argc, argv);
	stock = ft_join_args(argv);
	split = ft_split(stock);
	len = ft_arraylen(split);
	numbers = ft_creat_array(split, len);
	stack_a = ft_create_stack_a(numbers, len);
	ft_sort_array(numbers, len);
	ft_add_rank(stack_a, numbers, len);
	if(len <= 5)
		ft_less_than_five(&stack_a, &stack_b, len);
	ft_sort_with_chunk(&stack_a, &stack_b, len);
	ft_final_sort(&stack_b, &stack_a, len);
	ft_free_linked_list(stack_a);
	//  stack_a = NULL;
	// ft_swap(&stack_a, "ikhan\n");
	// while(stack_b)
	// {
	// 	indice = ft_maxnumber_indice(stack_b, len);
	// 	befor_max_indice = ft_maxnumber_indice(stack_b, len - 1);
	// 	if(indice < len / 2 && befor_max_indice < len / 2 && befor_max_indice < indice && len > 3)
	// 	{
	// 		ft_push_2_in_right(&stack_b, &stack_a, len);
	// 		len = len - 2;
	// 	}
	// 	else if(indice > len / 2 && befor_max_indice > len / 2 && befor_max_indice > indice && len > 3)
	// 	{
	// 		ft_push_2_in_left(&stack_b, &stack_a, len);
	// 		len = len - 2;
	// 	}
	// 	else
	// 		len = ft_normal_case(&stack_b, &stack_a, len, indice);
	// }
}


// sa = swap stack a = swap tow first data;   =>  3 8 4 6 =>   8 3  4 6
// same for sb;


// ra and rb  rotate
// make the first become the last  2 4 6 7 => 4 6 7 2

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



//you need to handle the case "1+2" and "1 2 9+" 





/* check count
	6 ---> 100 size /5
	101 ---> size /11
*/
// not chunks / hard coding
// sort 3  numbers
// sort 2 numbers
// sort 4/5 numbers

 //./a.out  $(seq 200 -200 | sort -R | head -n100) | wc -l  

