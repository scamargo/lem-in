/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:22:49 by scamargo          #+#    #+#             */
/*   Updated: 2017/12/04 20:03:46 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ret;

	ret = NULL;
	if (*s == (char)c)
		ret = (char*)s;
	while (*s++)
	{
		if (*s == (char)c)
			ret = (char*)s;
	}
	return (ret);
}
