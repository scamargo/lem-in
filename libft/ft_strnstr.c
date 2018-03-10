/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:40:53 by scamargo          #+#    #+#             */
/*   Updated: 2017/12/04 20:54:36 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t k;
	size_t m;

	i = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i] && i < len)
	{
		k = 0;
		m = i;
		while (little[k] && little[k] == big[m] && m < len)
		{
			k++;
			m++;
		}
		if (little[k] == '\0')
			return (&((char*)big)[i]);
		i++;
	}
	return (NULL);
}
