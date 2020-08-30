#ifndef LIST_H
# define LIST_H


#include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			size;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

t_list	*lst_new(void *content, size_t size);
void	lst_push(t_list **head, t_list *node);
t_list	*lst_pop(t_list **head);
void	lst_enqueue(t_list **head, t_list *last);
t_list	*lst_dequeue(t_list **head);
void	lst_del_one(t_list **node);
void	lst_del_content(t_list *node);
size_t	lst_len(t_list *head);
t_list *lst_get_index(t_list *head, int index);
void    lst_iter(t_list *lst, void (*f)(t_list *elem));

#endif