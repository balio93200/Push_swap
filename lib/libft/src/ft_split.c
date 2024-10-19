/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdiakhab <bdiakhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:14:21 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/11 13:38:22 by bdiakhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] == c)
				i++;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static void	ft_split_2(const char *s, char **split, char sep, int words)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i] == sep)
		i++;
	while (j < words)
	{
		start = i;
		while (s[i] != sep && s[i])
			i++;
		split[j] = malloc(sizeof(char) * (i - start + 1));
		ft_memmove(split[j], (s + start), (i - start));
		split[j][i - start] = '\0';
		while (s[i] == sep)
			i++;
		j++;
	}
}

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**split;

	words = count_words(s, c);
	if (s[ft_strlen(s) - 1] == c)
		words--;
	if (words < 0 || *s == '\0')
		return (split = malloc(sizeof(char *) * 1), split[0] = NULL, split);
	split = malloc(sizeof(char *) * (words + 1));
	ft_split_2(s, split, c, words);
	return (split[words] = NULL, split);
}
