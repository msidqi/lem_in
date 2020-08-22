#include "graph.h"

int *fill_content_int(int n)
{
	int		*content;

	content = malloc(sizeof(int));
	*content = n;
	return (content);
}

int main(void)
{
	t_graph *gnode[7];

	gnode[0] = gnode_new(fill_content_int(0), sizeof(int));
	gnode[1] = gnode_new(fill_content_int(1), sizeof(int));
	gnode[2] = gnode_new(fill_content_int(2), sizeof(int));
	gnode[3] = gnode_new(fill_content_int(3), sizeof(int));
	gnode[4] = gnode_new(fill_content_int(4), sizeof(int));
	gnode[5] = gnode_new(fill_content_int(5), sizeof(int));
	gnode[6] = gnode_new(fill_content_int(6), sizeof(int));
	link_gnodes_enqueue(gnode[0], gnode[1]);
	link_gnodes_enqueue(gnode[0], gnode[2]);
	link_gnodes_enqueue(gnode[1], gnode[3]);
	link_gnodes_enqueue(gnode[1], gnode[4]);
	link_gnodes_enqueue(gnode[2], gnode[5]);
	link_gnodes_enqueue(gnode[2], gnode[6]);
			// traverse_dfs_in_order(gnode[0]);
	// traverse_dfs_pre_order(gnode[0]);
	// traverse_dfs_post_order(gnode[0]);
	traverse_bfs(gnode[0]);
	return (0);
}
