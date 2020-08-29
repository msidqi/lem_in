#ifndef BST_H
# define BST_H

#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

typedef struct		s_graph
{
	t_list			*adjacency_list;
}                   t_graph;


typedef struct		s_gnode
{
	void			*content;
	size_t			size;
	int				visited;
	t_list			*neighbours;
	t_list			*iterator;
}					t_gnode;

t_gnode				*gnode_new(void *content, size_t size);
t_gnode				*get_neighbour_node(t_gnode *g);
void				link_gnodes_push(t_gnode *g0, t_gnode *g1);
void				link_gnodes_enqueue(t_gnode *g0, t_gnode *g1);
void				traverse_dfs_pre_order(t_gnode *start);
void				traverse_bfs(t_gnode *start);

#endif