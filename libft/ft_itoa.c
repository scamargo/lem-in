/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:46:13 by scamargo          #+#    #+#             */
/*   Updated: 2017/12/07 13:29:14 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_digits(long num)
{
	long	divisor;
	int		digits;

	divisor = 10;
	digits = 1;
	while (num / divisor)
	{
		divisor *= 10;
		digits++;
	}
	return (digits);
}

static void		set_itoa(char **str_ptr, long num)
{
	if (num < 0)
	{
		**str_ptr = '-';
		(*str_ptr)++;
		num *= -1;
	}
	if (num < 10)
	{
		**str_ptr = num + '0';
		(*str_ptr)++;
		return ;
	}
	set_itoa(str_ptr, num / 10);
	set_itoa(str_ptr, num % 10);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*str;
	char	*str_copy;
	long	num;

	num = n;
	len = 0;
	if (num < 0)
		len++;
	len += count_digits(num);
	if (!(str = malloc(len + 1)))
		return (NULL);
	str_copy = str;
	if (num < 0)
	{
		*str_copy = '-';
		str_copy++;
		num *= -1;
	}
	set_itoa(&str_copy, num);
	*str_copy = '\0';
	return (str);
}
