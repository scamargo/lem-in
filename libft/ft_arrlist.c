/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:27:31 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/23 16:45:17 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	resize_array(t_array *arr)
{
	char	*new_str;

	arr->size = arr->size * 2;
	new_str = ft_memalloc(((arr->size) + 1) * sizeof(char));
	ft_strcpy(new_str, arr->str);
	free(arr->str);
	arr->str[arr->used] = '\0';
	arr->str = new_str;
}

void		arr_insert(t_array *arr, char c)
{
	if (arr->used == arr->size)
		resize_array(arr);
	arr->str[arr->used++] = c;
}

t_array		*arr_init(int initial_size)
{
	t_array *buff;

	if (!(buff = ft_memalloc(sizeof(t_array))))
		return (0);
	buff->size = initial_size;
	buff->used = 0;
	if (!(buff->str = ft_memalloc((buff->size + 1) * sizeof(char))))
		return (0);
	buff->str[initial_size] = '\0';
	return (buff);
}
