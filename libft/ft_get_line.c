/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:05:14 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/13 10:05:29 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_line(char **p_buffer, char **p_line)
{
	int		i;
	char	*new;

	i = 0;
	if ((new = ft_strchr(*p_buffer, '\n')))
	{
		*new = '\0';
		new++;
		*p_line = *p_buffer;
		*p_buffer = ft_strdup(new);
		return (1);
	}
	*p_line = *p_buffer;
	*p_buffer = NULL;
	if (**p_line)
		return (1);
	ft_strdel(p_line);
	return (0);
}
