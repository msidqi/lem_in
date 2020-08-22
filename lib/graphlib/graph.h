#ifndef BST_H
# define BST_H

#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

typedef struct		s_graph
{
	void			*content;
	size_t			size;
	int				visited;
	t_list			*adjacency_list;
	t_list			*iterator;
}					t_graph;

t_graph				*gnode_new(void *content, size_t size);
t_graph				*get_adjacent_node(t_graph *g);
void				link_gnodes_push(t_graph *g0, t_graph *g1);
void				link_gnodes_enqueue(t_graph *g0, t_graph *g1);
void				traverse_dfs_pre_order(t_graph *start);
void				traverse_bfs(t_graph *start);

#endif