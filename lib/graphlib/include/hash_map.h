#ifndef HASH_MAP_H
# define HASH_MAP_H

# include <stdlib.h>
#include <string.h>
# include "lists.h"
# include "stacks_queues.h"

# define DEFAULT_MAP_LEN 100

typedef struct		s_map_elem
{
	void			*content;
	size_t			size;
	char			*key;
}					t_map_elem;

typedef struct		s_map
{
	size_t			_len;
	size_t			n_elem;
	t_queue			*map_array;
	size_t			(*_hash_func)(struct s_map *m, char *key);
	int 			(*insert)(struct s_map *m, char* key, void *content, size_t);
	void 			*(*insert_replace)(struct s_map *m, char* key, void *content, size_t);
	void			*(*get)(struct s_map *m, char *key);
	void			(*remove)(struct s_map *m, char *key);
	void			*(*extract)(struct s_map *m, char *key);
	int				(*exists)(struct s_map *m, char *key);
	int				(*is_empty)(struct s_map *m);
}					t_map;

t_map			map_create(size_t (*hash_func)(t_map *, char *key), size_t map_len);

#endif