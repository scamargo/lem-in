/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:14:16 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/12 15:00:37 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "stdio.h"

int		parse_input(t_lem *meta)
{
	char	*line;
	//int		result;

	if (get_next_line(0, &line) < 1)
		return (0);
	meta->number_of_ants = ft_atoi(line);
	if (meta->number_of_ants <= 0)
		return (0);
	/*if (!parse_ants(meta))
		return (0);
	if (!parse_rooms(meta))
		return (0);
	if (!parse_tubes(meta))
		return (0);*/
	return (1);
}

int		main(void)
{
	t_lem	*meta;

	if (!(meta = ft_memalloc(sizeof(t_lem))))
	{
		ft_putendl("MALLOC ERROR");
		return (2);
	}
	if (!parse_input(meta))
	{
		ft_putendl("ERROR");
		return (1);
	}
	return (0);
}
