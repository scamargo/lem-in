/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:32:39 by scamargo          #+#    #+#             */
/*   Updated: 2017/12/06 21:05:43 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char			*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	int		k;
	char	*str;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(str = malloc(len + 1)))
		return (NULL);
	while (is_space(*s))
		s++;
	i = 0;
	k = 0;
	while (*s)
	{
		while (*s && !is_space(*s))
			str[i++] = *s++;
		k = i;
		while (is_space(*s))
			str[i++] = *s++;
	}
	str[k] = '\0';
	return (str);
}
