/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:10:54 by jromann           #+#    #+#             */
/*   Updated: 2025/08/28 12:55:45 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	strrlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*strjoin(char const *s1, char const *s2, char c)
{
	int		i;
	int		k;
	char	*ptr;

	i = -1;
	k = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (strrlen((char *)s1)
				+ strrlen((char *)s2) + 2));
	if (ptr == NULL)
		return (NULL);
	while (s1[++i])
		ptr[i] = s1[i];
	ptr[i] = c;
	while (s2[++k])
		ptr[++i] = s2[k];
	ptr[++i] = 0;
	return (ptr);
}
