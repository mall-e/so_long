/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:22:02 by muyazici          #+#    #+#             */
/*   Updated: 2022/08/15 16:12:46 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	a;
	char	*dizi;

	i = -1;
	a = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	dizi = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!dizi)
		return (NULL);
	while (s1[++i] != '\0')
		dizi[i] = s1[i];
	while (s2[a] != '\0')
		dizi[i++] = s2[a++];
	dizi[i] = '\0';
	free (s1);
	return (dizi);
}

size_t	ft_strlen(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
