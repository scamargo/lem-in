/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:25:32 by scamargo          #+#    #+#             */
/*   Updated: 2017/12/04 18:01:38 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;
	int		k;
	int		n;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	while (dst[i])
		i++;
	n = size - i - 1;
	k = 0;
	while (src[k] && k < n)
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	if (size < dst_len)
		return (size + src_len);
	else
		return (dst_len + src_len);
}
