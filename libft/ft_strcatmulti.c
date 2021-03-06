/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcatmulti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:29:19 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/13 09:29:21 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcatmulti(char *s1, char *s2, size_t times)
{
	while (times--)
		ft_strcat(s1, s2);
}
