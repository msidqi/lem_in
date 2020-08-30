#include "lists.h"

t_list	*lst_new(void *content, size_t size)
{
	t_list *new_node;

	if(!(new_node = malloc(sizeof(t_list))))
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->size = size;
	return (new_node);
}

void	lst_del_one(t_list **node)
{
	if (!node || !(*node))
		return ;
	if ((*node)->content)
		free((*node)->content);
	free(*node);
	*node = NULL;
}

void	lst_del_content(t_list *node)
{
	if (!node || !node->content)
		return ;
	free(node->content);
	node->content = NULL;
	node->size = 0;
}

void	lst_push(t_list **head, t_list *node)
{
	node->next = *head;
	*head = node;
}

t_list	*lst_pop(t_list **head)
{
	t_list *node;

	if (!head || !(*head))
		return (NULL);
	node = (*head);
	*head = (*head)->next;
	return (node);
}

void	lst_enqueue(t_list **head, t_list *last)
{
	t_list *iterator;

	if (!*head)
	{
		*head = last;
		return ;
	}
	iterator = *head;
	while (iterator->next)
	{
		iterator = iterator->next;
	}
	iterator->next = last;
}

t_list	*lst_dequeue(t_list **head)
{
	t_list *node;

	if (!head || !(*head))
		return (NULL);
	node = (*head);
	*head = (*head)->next;
	return (node);
}

t_list	*lst_pop_last(t_list **head)
{
	t_list *tmp;
	t_list *iterator;

	if (!head || !(*head))
		return (NULL);
	iterator = *head;
	if (!(*head)->next)
	{
		*head = NULL;
		return (iterator);
	}
	while (iterator->next)
	{
		tmp = iterator;
		iterator = iterator->next;
	}
	tmp->next = NULL;
	return (iterator);
}

size_t lst_len(t_list *head)
{
	size_t i;

	if (!head)
		return (0);
	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

t_list *lst_get_index(t_list *head, int index)
{
	int		i;
	t_list	*iter;

	if (index < 0)
		return (NULL);
	i = 0;
	iter = head;
	while (iter)
	{
		if (i == index)
			return (iter);
		iter = iter->next;
		i++;
	}
	return (NULL);
}

void    lst_iter(t_list *lst, void (*f)(t_list *elem))
{
    while (lst != NULL)
    {
        f(lst);
        lst = lst->next;
    }
}
