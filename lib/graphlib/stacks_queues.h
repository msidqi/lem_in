#ifndef STACKS_QUEUES_H
# define STACKS_QUEUES_H

#include <stdlib.h>
#include "lists.h"

typedef struct	s_queue
{
	t_list		*_first;
	t_list		*_last;
	size_t		(*len)(struct s_queue *q);
	void		(*enqueue)(struct s_queue *q, t_list *node);
	t_list		*(*enqueue_new)(struct s_queue *q, void *content, size_t size);
	t_list		*(*dequeue)(struct s_queue *q);
	// t_list		*(*index)(struct s_queue *q, int index);

}				t_queue;

typedef struct	s_stack
{
	t_list		*_first;
	size_t		(*len)(struct s_stack *s);
	void		(*push)(struct s_stack *s, t_list *node);
	t_list		*(*push_new)(struct s_stack *s, void *content, size_t size);
	t_list		*(*pop)(struct s_stack *s);
	// t_list		*(*index)(struct s_stack *s, int index);

}				t_stack;

t_stack			stack_create();
t_queue			queue_create();

#endif