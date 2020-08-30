
#include "stacks_queues.h"

t_list	*stack_pop(t_stack *s)
{
	return (lst_pop(&s->_first));	
}

void		stack_push(t_stack *s, t_list *to_push)
{
	lst_push(&s->_first, to_push);
}

t_list	*stack_push_new(t_stack *s, void *content, size_t size)
{
	t_list	*new_node = lst_new(content, size);
	lst_push(&s->_first, new_node);
	return (new_node);
}

size_t	stack_len(t_stack *s)
{
	if (!s)
		return (0);
	return (lst_len(s->_first));
}

int  	stack_is_empty(t_stack *s)
{
	if (!s || !s->_first)
		return (1);
    return (0);
}

t_stack			stack_create()
{
	t_stack s;

    // s.is_empty = stack_is_empty;
	// s.len = stack_len;
	// s.push = stack_push;
	// s.pop = stack_pop;
	// s.push_new = stack_push_new;
	s._first = NULL;
	return (s);
}

t_stack			*stack_new()
{
	t_stack *s;

    s = (t_stack *)malloc(sizeof(t_stack));
	s->_first = NULL;
	return (s);
}
