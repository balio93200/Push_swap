/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdiakhab <bdiakhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:09:08 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/11 13:17:20 by bdiakhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	size;

	if (len > ft_strlen(s))
		size = ft_strlen(s);
	else
		size = len;
	str = malloc(sizeof(char) * (size + 1));
	if (!s || !str)
		return (NULL);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < size)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
