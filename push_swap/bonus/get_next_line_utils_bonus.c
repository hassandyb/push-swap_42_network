/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:41:01 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/04/16 21:57:09 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strchr(char *str, char c)
{
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}


char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	if (s1 == NULL)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		result[i++] = s2[j++];
	result[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (result);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	slen;
	size_t	i;

	i = 0;
	if (!s || !(*s))
		return (NULL);
	slen = ft_strlen(s);
	p = (char *)malloc(len + 1);
	if (p == NULL)
		return (NULL);
	while (s[i + start] != '\0' && i < len)
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}