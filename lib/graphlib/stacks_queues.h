#ifndef STACKS_QUEUES_H
# define STACKS_QUEUES_H

#include <stdlib.h>
#include "lists.h"

typedef struct	s_queue
{
	t_list		*_first;
	t_list		*_last;
	size_t		(*len)(t_queue *q);
	void		(*enqueue)(t_queue *q, t_list *node);
	t_list		*(*enqueue_new)(t_queue *q, void *content, size_t size);
	t_list		*(*dequeue)(t_queue *q);
}				t_queue;

typedef struct	s_stack
{
	t_list		*_first;
	size_t		(*len)(t_stack *s);
	void		(*push)(t_stack *s, t_list *node);
	t_list		*(*push_new)(t_stack *s, void *content, size_t size);
	t_list		*(*pop)(t_stack *s);
}				t_stack;

#endif