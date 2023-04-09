/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:35:50 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/09 22:07:06 by hed-dyb          ###   ########.fr       */
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
void ft_sort_array(int *numbers, int len)
{
	int i;
	int swap;
	i = 0;
	while(i<len - 1)
	{
		if(numbers[i] > numbers[i+1])
		{
			swap = numbers[i];
			numbers[i] = numbers[i+1];
			numbers[i+1] = swap;
			i = 0;
		}
		else
			i++;
	}
}

void ft_add_rank(t_stack *ptr, int *numbers, int len)
{
	int j;
	int i;
	j = 0;
	while(ptr)
	{
		i = 0;
		while(i < len)
		{
			if(ptr->data == numbers[i])
			{
				ptr->rank = i;
				break ;
			}
			i++;
		}
		ptr = ptr->next;
	}
	free(numbers);
}
// -------------------------------
void ft_sort(t_stack **a, t_stack **b,int len)
{
	// int max = len/5;
	int chunk;
	int count;
	int indice;
	
	if(len >= 6 && len <= 100)
		chunk = len / 10;
	else
		chunk = len / 11;
	count = 0;
	indice = 1;
	while(*a != NULL)
	{
		while( *a != NULL && count < chunk)
		{
			if((*a)->rank < (chunk * indice))//we try to ing the numbers of our chunk
			{
				count++;
				ft_push(a, b, "pb\n");
				if((*b)->rank >= (chunk * indice) - ((chunk * indice) / 2))// we split the chunk numbers big at end small at the beginig - while to get the chank numbers we split them ==>big numbers -->rorate ->we to the end | and we keep small numbers in the beging of our linkedlist
					ft_rotate(b, "rb\n");
			}
			else
				ft_rotate(a, "ra\n");
		}
		count = 0;
		chunk = chunk + (len/5);
	}
}
//create a function  which return the position 
int ft_maxnumber_indice(t_stack *list, int len)
{
	int i;

	i = 0;
	while(list)
	{
		if(list->rank == len - 1)
		{
			return (i);
		}
		list = list->next;
		i++;
	}
	return (i);
}

void ft_sort_2(t_stack **b, t_stack **a,int len, int indice)
{
	t_stack *temp;
	
	while(*b)
	{
		// if(indice < len / 2)// the max is in the begining
		// {
		// 	while(*b)
		// 	{
		// 		if((*b)->rank == len - 1)
		// 		{
		// 			ft_push(b, a, "pa\n");
		// 			break ;
		// 		}
		// 		ft_rotate(b, "rb\n");
		// 	}
		// }
		
		// else //the mas is in the last;
		// {
		// 	while(*b)
		// 	{
		// 		ft_reverse_rotate(b, "rrb");
		// 		if((*b)->rank == len - 1)
		// 		{
		// 			ft_push(b, a, "pb\n");
		// 			break ;
		// 		}
				
		// 	}
		// }
		if((*b)->rank == len - 1)
		{
			ft_push(b, a, "pa\n");
			len--;
			indice = ft_maxnumber_indice(*b, len);
		}
		else if(indice < len /2)
			ft_rotate(b, "rb\n");
		else  if(indice >= len /2)
			ft_reverse_rotate(b, "rrb\n");
		
	}
}

int main (int argc, char **argv)
{
	char 	*stock;
	char 	**split;
	int		*numbers;
	int		len;
	t_stack *stack_a;
	t_stack	*stack_b;
	int indice;
	

	stack_a = NULL;
	stack_b = NULL;
	if(argc == 1)
		exit (0);
	ft_check1(argv);
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
	ft_sort_array(numbers, len);
	ft_add_rank(stack_a, numbers, len);// add and remove & and see what happsns.
	//----

	ft_sort(&stack_a, &stack_b, len);
	indice = ft_maxnumber_indice(stack_b, len);
	ft_sort_2(&stack_b, &stack_a, len, indice);

	//-----
	
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
// sort 3 numbers
// sort 4/5 numbers
 //./a.out  $(seq 200 -200 | sort -R | head -n100) | wc -l  