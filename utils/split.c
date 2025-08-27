/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:46:40 by jromann           #+#    #+#             */
/*   Updated: 2025/08/27 15:39:02 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	wordcounter(char const *s, char c)
{
	int	i;
	int	b;
	int	wordcount;

	i = -1;
	b = 0;
	wordcount = 0;
	while (s[++i])
	{
		if (s[i] == c && b == 1)
			b = 0;
		else if (!(s[i] == c) && b == 0)
		{
			wordcount++;
			b = 1;
		}
	}
	return (wordcount);
}

static int	substrlen(char const *s1, char c)
{
	int	i;
	int	length;

	i = -1;
	length = 0;
	while (s1[++i])
	{
		if (s1[i] == c)
			return (length);
		length++;
	}
	return (length);
}

static char	*create_array(int length, char const *s)
{
	char	*arr;
	int		k;
	int		index;
	int		i;

	index = 0;
	k = -1;
	length += 1;
	i = -1;
	arr = (char *)malloc(sizeof(char) * length);
	if (!arr)
		return (NULL);
	while (--length > 0)
		arr[++k] = s[index++];
	arr[++k] = 0;
	return (arr);
}

static char	**wordforword(int wordcount, char const *s, char c, char **arr)
{
	int	i;
	int	index;
	int	length;

	i = -1;
	index = 0;
	while (wordcount > 0)
	{
		length = substrlen(&s[index], c);
		if (length)
		{
			arr[++i] = create_array(length, &s[index]);
			if (!arr[i])
				return (free2d(arr), NULL);
			wordcount--;
			index += (length - 1);
		}
		index++;
	}
	arr[++i] = NULL;
	return (arr);
}

char	**split(char const *s, char c)
{
	int		wordcount;
	char	**arr;

	wordcount = wordcounter(s, c);
	arr = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (arr == NULL)
		return (NULL);
	return (wordforword(wordcount, s, c, arr));
}
