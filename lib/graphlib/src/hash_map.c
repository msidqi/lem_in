#include "hash_map.h"

static size_t	default_hash_func(t_map *map, char *key)
{
	size_t i;
	size_t total;

	i = 0;
	total = 0;
	while (key[i])
		total += key[i++];
	return (total % map->_len);
}

static void		map_insert(t_map *m, char* key, void *content, size_t s)
{
	size_t index;

	index = m->_hash_func(m, key);
    // if (m->map[index].content)
        // lst_enqueue(&m->map[index], lst_new(content, s));
    // else
    // {
        m->map[index].content = content;
        m->map[index].size = s;
    // }
}

t_map			map_create(size_t (*hash_func)(t_map *, char *), size_t map_len)
{
	t_map m;

	m._len = map_len > 10 ? map_len : DEFAULT_MAP_LEN;
	m.map = malloc(m._len * sizeof(t_list));
	bzero(m.map, m._len * sizeof(t_list));
    
    m.map_array = malloc(m._len * sizeof(t_queue));
	bzero(m.map_array, m._len * sizeof(t_queue));

	m._hash_func = hash_func ? hash_func : default_hash_func;
	m.n_elem = 0;
	// m.is_empty = map_is_empty;
	// m.remove = map_remove;
	m.insert = map_insert;
	// m.extract = map_extract;
	// m.exists = map_key_exists;
	// m.get = map_get;
	return (m);
}
