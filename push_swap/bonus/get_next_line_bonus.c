/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:10:48 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/16 21:54:10 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_line_len(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*get_after_newline(char *stock)
{
	char	*temp;
	int		a;
	int		i;

	i = 0;
	while (stock[i] != '\n')
	{
		if (stock[i] == '\0')
			return (free(stock), NULL);
		i++;
	}
	a = i + 1;
	while (stock[i] != '\0')
		i++;
	temp = ft_substr(stock, a, i - a);
	free(stock);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stock;
	char		*line;
	int			a;

	a = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_strchr(stock, '\n') == 0 && a > 0)
	{
		a = read (fd, buffer, BUFFER_SIZE);
		if (a == -1)
			return (free (stock), free (buffer), NULL);
		buffer[a] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
	
	free(buffer);
	line = ft_substr(stock, 0, ft_line_len(stock) + 1);
	stock = get_after_newline(stock);
	return (line);
}
