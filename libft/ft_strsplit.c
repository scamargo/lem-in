/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:56:44 by scamargo          #+#    #+#             */
/*   Updated: 2017/12/06 21:10:36 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *s, char delimeter)
{
	int count;

	count = 0;
	while (*s == delimeter)
		s++;
	while (*s)
	{
		while (*s && *s != delimeter)
			s++;
		count++;
		while (*s == delimeter)
			s++;
	}
	return (count);
}

static char		*build_word(char const *str, int *index, char delim)
{
	char	*new_str;
	int		start;
	int		end;
	int		i;

	i = *index;
	while (str[i] == delim)
		i++;
	start = i;
	while (str[i] && str[i] != delim)
		i++;
	end = i;
	*index = end;
	if (!(new_str = (char*)malloc(end - start + 1)))
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		new_str[i] = str[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		word_count;
	int		tab_index;
	int		i;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	tab = malloc(sizeof(char*) * (word_count + 1));
	if (!tab)
		return (NULL);
	tab_index = 0;
	i = 0;
	while (word_count)
	{
		tab[tab_index++] = build_word(s, &i, c);
		word_count--;
	}
	tab[tab_index] = 0;
	return (tab);
}
