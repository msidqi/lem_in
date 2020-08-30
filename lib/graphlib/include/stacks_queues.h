#ifndef STACKS_QUEUES_H
# define STACKS_QUEUES_H

#include <stdlib.h>
#include "lists.h"

typedef struct	s_queue
{
	t_list		*_first;
	t_list		*_last;
	// size_t		(*len)(struct s_queue *q);
	// void		(*enqueue)(struct s_queue *q, t_list *node);
	// t_list		*(*enqueue_new)(struct s_queue *q, void *content, size_t size);
	// t_list		*(*dequeue)(struct s_queue *q);
	// int  	    (*is_empty)(struct s_queue *q);
	// t_list		*(*index)(struct s_queue *q, int index);

}				t_queue;

typedef struct	s_stack
{
	t_list		*_first;
	// size_t		(*len)(struct s_stack *s);
	// void		(*push)(struct s_stack *s, t_list *node);
	// t_list		*(*push_new)(struct s_stack *s, void *content, size_t size);
	// t_list		*(*pop)(struct s_stack *s);
	// int  	    (*is_empty)(struct s_stack *s);
	// t_list		*(*index)(struct s_stack *s, int index);

}				t_stack;

t_stack			stack_create();
t_stack			*stack_new();
t_list			*stack_pop(t_stack *s);
void			stack_push(t_stack *s, t_list *to_push);
t_list			*stack_push_new(t_stack *s, void *content, size_t size);
size_t			stack_len(t_stack *s);
int				stack_is_empty(t_stack *s);

t_queue			queue_create();
t_queue			*queue_new();
void			queue_enqueue(t_queue *q, t_list *node);
t_list			*queue_enqueue_new(t_queue *q, void *content, size_t size);
t_list			*queue_dequeue(t_queue *q);
size_t			queue_len(t_queue *q);
int				queue_is_empty(t_queue *q);

#endif