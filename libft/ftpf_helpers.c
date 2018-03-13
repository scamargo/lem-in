/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:30:50 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/13 09:30:53 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_printf.h"

char	*ftpf_ultoa_base(uint64_t nbr, int base)
{
	uint64_t	cpy;
	uint8_t		length;
	char		*returned;

	cpy = nbr;
	length = 0;
	while (cpy)
	{
		cpy /= base;
		++length;
	}
	if (!nbr)
		++length;
	returned = malloc(sizeof(*returned) * (length + 1));
	returned[length--] = '\0';
	if (!nbr)
		returned[0] = '0';
	while (nbr)
	{
		returned[length--] = "0123456789abcdef"[nbr % base];
		nbr /= base;
	}
	return (returned);
}

char	*ftpf_ltoa_10(int64_t nbr)
{
	char	*tmp;
	char	*returned;
	char	l[2];

	if (nbr >= 0)
		return (ftpf_ultoa_base(nbr, 10));
	l[0] = ((nbr % 10) * -1) + '0';
	l[1] = '\0';
	nbr = (nbr / 10) * -1;
	if (nbr)
	{
		tmp = ftpf_ultoa_base(nbr, 10);
		returned = malloc(ft_strlen(tmp) + 3);
		ft_strcpy(returned, "-");
		ft_strcat(returned, tmp);
		free(tmp);
	}
	else
	{
		returned = malloc(3);
		ft_strcpy(returned, "-");
	}
	ft_strcat(returned, l);
	return (returned);
}

void	ftpf_resetpart(void)
{
	g_part.width = 0;
	g_part.prec = 0;
	g_part.arg = 0;
	g_part.flags = 0;
	g_part.p = 0;
	g_part.length = 0;
}

char	*ftpf_pad(char *str, size_t *len, size_t strl)
{
	char	*tmp;
	char	*thold;
	char	*shold;
	char	pad;

	pad = (g_part.flags & ZER && !(g_part.flags & NEG)) ? '0' : ' ';
	shold = str;
	tmp = ft_strnew(g_part.width);
	thold = tmp;
	g_part.width -= strl;
	*len += g_part.width;
	g_part.len += g_part.width;
	if (g_part.flags & NEG)
		while (*str)
			*tmp++ = *str++;
	while (g_part.width)
	{
		*tmp++ = pad;
		--g_part.width;
	}
	if (!(g_part.flags & NEG))
		while (*str)
			*tmp++ = *str++;
	free(shold);
	return (thold);
}
