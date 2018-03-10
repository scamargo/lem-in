/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddtoend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 22:29:19 by scamargo          #+#    #+#             */
/*   Updated: 2017/12/19 17:21:53 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddtoend(t_list **head, t_list *new)
{
	t_list	*last;

	last = *head;
	if (!last)
	{
		*head = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}
