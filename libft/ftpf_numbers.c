/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:31:40 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/13 09:31:50 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_printf.h"

void		ftpf_signedmods(char **str, size_t *tlen, size_t len)
{
	char	*tmp;

	if (len != ft_strlen(*str))
	{
		tmp = ft_strnew(len);
		if (!(g_part.flags & (NEG | ZER)) && g_part.width)
			ft_strcatmulti(tmp, " ", g_part.width);
		if (**str == '-')
			ft_strcat(tmp, "-");
		else if (g_part.flags & (PLS | SPC))
			ft_strcat(tmp, (g_part.flags & PLS) ? "+" : " ");
		if ((g_part.flags & ZER) && !(g_part.flags & NEG) && g_part.width)
			ft_strcatmulti(tmp, (g_part.flags & ZER) ? "0" : " ", g_part.width);
		if (g_part.prec)
			ft_strcatmulti(tmp, "0", g_part.prec);
		ft_strcat(tmp, (**str == '-') ? (*str) + 1 : *str);
		if ((g_part.flags & NEG) && g_part.width)
			ft_strcatmulti(tmp, " ", g_part.width);
		free(*str);
		*str = tmp;
	}
	*tlen += len;
	g_part.len = len;
}

char		*ftpf_signed(size_t *len, va_list ap)
{
	char	*returned;
	size_t	slen;

	if (g_part.length & (l | ll | j | z))
		returned = ftpf_ltoa_10(va_arg(ap, long));
	else if (g_part.length & h)
		returned = ftpf_ltoa_10((short)va_arg(ap, int));
	else if (g_part.length & hh)
		returned = ftpf_ltoa_10((char)va_arg(ap, int));
	else
		returned = ftpf_ltoa_10(va_arg(ap, int));
	if (g_part.p && *returned == '0')
		*returned = '\0';
	if ((g_part.p && (g_part.flags & ZER)) || (g_part.flags & NEG))
		g_part.flags ^= ZER;
	if ((g_part.flags & (PLS | SPC)) == (PLS | SPC))
		g_part.flags ^= SPC;
	slen = (*returned == '-') ? ft_strlen(returned) - 1 : ft_strlen(returned);
	g_part.prec -= (g_part.prec > slen) ? slen : g_part.prec;
	slen += (*returned == '-') ? g_part.prec + 1 : g_part.prec;
	slen += ((g_part.flags & (PLS | SPC)) && *returned != '-') ? 1 : 0;
	g_part.width -= (g_part.width > slen) ? slen : g_part.width;
	slen += g_part.width;
	ftpf_signedmods(&returned, len, slen);
	return (returned);
}

static void	ftpf_usmresolve(char **str, char *tmp, size_t *tlen, size_t len)
{
	free(*str);
	*str = tmp;
	*tlen += len;
	g_part.len = len;
}

void		ftpf_unsignedmods(char **str, size_t *tlen, size_t len)
{
	char	*tmp;

	if (**str == '0' && g_part.p)
	{
		**str = '\0';
		--len;
	}
	g_part.prec -= (g_part.prec > len) ? len : g_part.prec;
	len += (g_part.flags & ALT) ? g_part.prec + 2 : g_part.prec;
	g_part.width -= (g_part.width > len) ? len : g_part.width;
	len += g_part.width;
	tmp = ft_strnew(len);
	if (!(g_part.flags & (NEG | ZER)) && g_part.width)
		ft_strcatmulti(tmp, " ", g_part.width);
	if (g_part.flags & ALT)
		ft_strcat(tmp, (g_part.base == 16) ? "0x" : "0b");
	if ((g_part.flags & ZER) && !(g_part.flags & NEG) && g_part.width)
		ft_strcatmulti(tmp, "0", g_part.width);
	ft_strcatmulti(tmp, "0", g_part.prec);
	ft_strcat(tmp, *str);
	if ((g_part.flags & NEG) && g_part.width)
		ft_strcatmulti(tmp, (g_part.flags & ZER) ? "0" : " ", g_part.width);
	if (g_part.flags & X)
		ft_strupper(tmp);
	ftpf_usmresolve(str, tmp, tlen, len);
}

char		*ftpf_unsigned(size_t *len, va_list ap)
{
	char	*returned;
	size_t	slen;

	if (g_part.length & (l | ll | j | z))
		returned = ftpf_ultoa_base(va_arg(ap, uint64_t), g_part.base);
	else if (g_part.length & h)
		returned = ftpf_ultoa_base((uint16_t)va_arg(ap, uint32_t), g_part.base);
	else if (g_part.length & hh)
		returned = ftpf_ultoa_base((uint8_t)va_arg(ap, uint32_t), g_part.base);
	else
		returned = ftpf_ultoa_base(va_arg(ap, uint32_t), g_part.base);
	slen = ft_strlen(returned);
	if (g_part.base == 8 && (g_part.flags & ALT))
	{
		g_part.flags ^= ALT;
		++g_part.p;
		g_part.prec = (g_part.prec > slen) ? g_part.prec : slen + 1;
		g_part.prec -= (*returned == '0') ? 1 : 0;
	}
	if ((g_part.flags & ZER) && ((g_part.flags & NEG) || g_part.p))
		g_part.flags ^= ZER;
	if ((g_part.flags & ALT) && *returned == '0')
		g_part.flags ^= ALT;
	ftpf_unsignedmods(&returned, len, slen);
	return (returned);
}
