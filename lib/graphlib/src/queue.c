#include "stacks_queues.h"

void		queue_enqueue(t_queue *q, t_list *node)
{
	if (!q->_first)
	{
		q->_first = node;
		q->_last = node;
	}
	else
	{
		q->_last->next = node;
		q->_last = node;
	}
}

t_list	*queue_enqueue_new(t_queue *q, void *content, size_t size)
{
	t_list *new_node;
	
	new_node = lst_new(content, size);
	queue_enqueue(q, new_node);
	return (new_node);
}

t_list	*queue_dequeue(t_queue *q)
{
	t_list *node;

	node = q->_first;
	if (q->_first)
	{
		if (q->_first == q->_last)
		{
			q->_first = NULL;
			q->_last = NULL;
		}
		else
			q->_first = q->_first->next;
	}
	return (node);
}

size_t	queue_len(t_queue *q)
{
    return (!q ? 0 : lst_len(q->_first));
}

int  	queue_is_empty(t_queue *q)
{
    return ((!q || !q->_first) ? 1 : 0);
}

t_queue			queue_create()
{
	t_queue q;

    // q.is_empty = queue_is_empty;
	// q.len = queue_len;
	// q.dequeue = queue_dequeue;
	// q.enqueue = queue_enqueue;
	// q.enqueue_new = queue_enqueue_new;
	q._last = NULL;
	q._first = NULL;
	return (q);
}

t_queue			*queue_new()
{
	t_queue *q;

    q = (t_queue *)malloc(sizeof(t_queue));
	q->_first = NULL;
	q->_last = NULL;
	return (q);
}
