/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:07:54 by scamargo          #+#    #+#             */
/*   Updated: 2017/12/07 20:30:09 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*current;

	if (!lst)
		return (NULL);
	if (!(head = f(lst)))
		return (NULL);
	current = head;
	while (lst->next)
	{
		if (!(current->next = f(lst->next)))
			return (NULL);
		current = current->next;
		lst = lst->next;
	}
	return (head);
}
