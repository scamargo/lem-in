/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:30:28 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/13 09:30:31 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_printf.h"

bool	ftpf_wild(const char **format, bool type, va_list ap)
{
	int64_t tmp;

	tmp = va_arg(ap, int);
	++(*format);
	if (type)
	{
		if (tmp < 0)
		{
			tmp *= -1;
			g_part.flags |= NEG;
		}
		g_part.width = tmp;
	}
	else
	{
		if (tmp < 0)
		{
			g_part.prec = 0;
			g_part.p = 0;
		}
		else
			g_part.prec = tmp;
	}
	return (1);
}

bool	ftpf_checknums(const char **format, va_list ap)
{
	int64_t tmp;

	if (**format == '*')
		return (ftpf_wild(format, FTPF_WIDTH, ap));
	else if (ft_isdigit(**format))
	{
		tmp = 0;
		while (ft_isdigit(**format))
		{
			tmp = (tmp * 10) + **format - '0';
			++(*format);
		}
		if (**format == '$')
		{
			g_part.arg = tmp;
			++(*format);
		}
		else
			g_part.width = tmp;
		return (1);
	}
	return (0);
}

bool	ftpf_checkprecision(const char **format, va_list ap)
{
	if (**format == '.')
	{
		g_part.p = 1;
		++(*format);
		if (**format == '*')
			return (ftpf_wild(format, FTPF_PRECISION, ap));
		else
		{
			g_part.prec = 0;
			while (ft_isdigit(**format))
			{
				g_part.prec *= 10;
				g_part.prec += **format - '0';
				++(*format);
			}
		}
		return (1);
	}
	return (0);
}

bool	ftpf_checkflags(const char **format)
{
	static const char	*flags = "#0- +";
	uint8_t				i;

	i = 0;
	while (flags[i] && flags[i] != **format)
		i++;
	if (flags[i])
	{
		g_part.flags |= (1 << i);
		++(*format);
		return (1);
	}
	return (0);
}

bool	ftpf_checklength(const char **format)
{
	static const char	*length = "hljz";
	int					i;

	i = 0;
	while (length[i] && length[i] != **format)
		i++;
	if (length[i])
	{
		++(*format);
		if (i <= 1)
		{
			if (**format == length[i])
			{
				g_part.length |= (i) ? ll : hh;
				++(*format);
			}
			else
				g_part.length |= (i) ? l : h;
		}
		else
			g_part.length |= (j << (i - 2));
		return (1);
	}
	return (0);
}
