/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:07:40 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/10 14:27:30 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	int		len;
	int		i;
	char	temp;

	len = ft_strlen(str);
	i = -1;
	while (++i < --len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
	}
}
