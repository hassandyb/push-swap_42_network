/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:24:18 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/03/30 14:13:00 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>


int ft_atoi(char *s)
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
		{
			sign = -1;
			i++;
		}
	}
	while(s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10) + s[i] - '0';
		i++;
	}
	return (result * sign);
}


int main()
{
	printf("%d", ft_atoi("123456"));
}