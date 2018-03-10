/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:40:57 by scamargo          #+#    #+#             */
/*   Updated: 2017/12/03 20:59:37 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	str_size;
	char	*dst;

	str_size = ft_strlen(s1);
	if (!(dst = malloc(str_size + 1)))
		return (NULL);
	return (ft_memcpy(dst, s1, str_size + 1));
}
