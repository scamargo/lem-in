#include "libft.h"

int		ft_is_queue_empty(t_queue *queue)
{
	if (!queue || !queue->first)
		return (1);
	return (0);
}

void		*ft_queue_peek(t_queue *queue)
{
	if (!queue || !queue->first)
		return (NULL);
	return (queue->first->content);
}

void		*ft_dequeue(t_queue *queue)
{
	void *content;
	struct s_node *old_first;
	
	if (!queue || !queue->first)
		return (NULL);
	content = queue->first->content;
	old_first = queue->first;
	if (queue->first == queue->last)
	{
		queue->first = NULL;
		queue->last = NULL;
	}
	else
		queue->first = queue->first->next;
	free(old_first);
	return (content);
}

void		ft_enqueue(t_queue *queue, void *content)
{
	struct s_node *node;
	
	if (!queue)
		return ;
	if ((node = (struct s_node*)ft_memalloc(sizeof(struct s_node))))
	{
		node->content = content;
		node->next = NULL;
		if (!queue->first)
			queue->first = node;
		else
			queue->last->next = node;
		queue->last = node;
	}
}
t_queue		*ft_queue_init(void)
{
	t_queue	*queue;

	if ((queue = (t_queue*)ft_memalloc(sizeof(t_queue))))
	{
		queue->first = NULL;
		queue->last = NULL;
		return (queue);
	}
	return (NULL);
}
