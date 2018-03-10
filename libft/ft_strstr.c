/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:05:05 by scamargo          #+#    #+#             */
/*   Updated: 2017/12/04 20:40:06 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int k;
	int m;

	i = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i])
	{
		k = 0;
		m = i;
		while (little[k] && little[k] == big[m])
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
