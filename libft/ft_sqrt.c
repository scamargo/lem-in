/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:53:40 by scamargo          #+#    #+#             */
/*   Updated: 2017/12/08 16:55:49 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int sqr;
	int root;

	sqr = 1;
	root = 1;
	while (sqr != nb)
	{
		root++;
		sqr = root * root;
		if (sqr > nb)
			return (0);
	}
	return (root);
}
