/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:13:14 by scamargo          #+#    #+#             */
/*   Updated: 2017/12/05 16:23:22 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(sub = malloc(len + 1)))
		return (NULL);
	while (len > 0)
	{
		sub[i] = s[start];
		i++;
		start++;
		len--;
	}
	sub[i] = '\0';
	return (sub);
}
