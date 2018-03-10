/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_chartable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 21:46:15 by scamargo          #+#    #+#             */
/*   Updated: 2017/12/17 21:48:28 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_init_chartable(size_t width, size_t height)
{
	char	**tab;
	size_t	i;

	if (!(tab = (char**)ft_memalloc(sizeof(char*) * height)))
		return (NULL);
	if (!(tab[0] = (char*)ft_memalloc(sizeof(char) * width * height)))
		return (NULL);
	i = 0;
	while (i < height)
	{
		tab[i] = *tab + width * i;
		i++;
	}
	return (tab);
}
