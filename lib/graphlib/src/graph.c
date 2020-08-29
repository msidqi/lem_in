#include "graph.h"

t_gnode *gnode_new(void *content, size_t size)
{
	t_gnode *node;

	if (!(node = malloc(sizeof(t_gnode))))
		return (NULL);
	node->content = content;
	node->size = size;
	node->neighbours = NULL;
	node->iterator = NULL;
	node->visited = 0;
	return (node);
}

void	link_gnodes_push(t_gnode *g0, t_gnode *g1)
{
	lst_push(&g0->neighbours, lst_new(g1, sizeof(t_gnode)));
}

void	link_gnodes_enqueue(t_gnode *g0, t_gnode *g1)
{
	lst_enqueue(&g0->neighbours, lst_new(g1, sizeof(t_gnode)));
}

t_gnode	*get_neighbour_node(t_gnode *g)
{
	if (!g->iterator)
	{
		g->iterator = g->neighbours;
	}
	else
	{
		g->iterator = g->iterator->next;
	}
	return (g->iterator ? (t_gnode *)g->iterator->content : NULL);
}

void	traverse_dfs_post_order(t_gnode *start)
{
	t_gnode *i;

	start->visited = 1;
	while ((i = get_neighbour_node(start)) && !i->visited)
	{
		traverse_dfs_post_order(i);
	}
	printf("%d\n", *((int *)start->content));
}

void	traverse_dfs_pre_order(t_gnode *start)
{
	t_gnode *i;

	printf("%d\n", *((int *)start->content));
	start->visited = 1;
	while ((i = get_neighbour_node(start)) && !i->visited)
	{
		traverse_dfs_pre_order(i);
	}
}

// void	traverse_dfs_in_order(t_gnode *start)

void	traverse_bfs(t_gnode *start)
{
	t_gnode *i;
	t_list *tmp;
	t_list *queue;

	if (!start)
		return ;
	queue = NULL;
	tmp = lst_new(start, sizeof(t_gnode));
	while (tmp)
	{
		printf("%d\n", *((int *)((t_gnode *)tmp->content)->content));
		((t_gnode *)tmp->content)->visited = 1;
		while ((i = get_neighbour_node((t_gnode *)tmp->content)))
		{
			if (!i->visited)
				lst_enqueue(&queue, lst_new(i, sizeof(t_gnode)));
		}
		free(tmp);
		tmp = lst_dequeue(&queue);
	}
}
