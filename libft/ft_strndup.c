/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:40:57 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/12 21:47:43 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	size_t	str_size;
	char	*dst;

	str_size = ft_strlen(s1);
	if (str_size < len)
		len = str_size;
	if (!(dst = malloc(len + 1)))
		return (NULL);
	return (ft_memcpy(dst, s1, len + 1));
}
