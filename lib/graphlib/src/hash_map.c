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

static int      map_is_empty(t_map *m)
{
	return ((!m || m->n_elem == 0) ? 1 : 0);
}

static void			map_elem_del_content(t_map_elem **e)
{
	if (!e || !(*e))
		return ;
	if ((*e)->content)
		free((*e)->content);
	if ((*e)->key)
		free((*e)->key);
	free((*e));
	*e = NULL;
}

static void			map_elem_del(t_map_elem **e)
{
	if (!e || !(*e))
		return ;
	if ((*e)->key)
		free((*e)->key);
	free(e);
	*e = NULL;
}

static t_map_elem	*map_elem_new(char* key, void *content, size_t s)
{
	t_map_elem *e;
	size_t key_len;

	key_len = strlen(key);
	if (!key_len || !(e = (t_map_elem *)malloc(sizeof(t_map_elem))))
		return (NULL);
	if (!(e->key = malloc(key_len + 1)))
	{
		free(e);
		return (NULL);
	}
	e->content = content;
	e->size = s;
	strncpy(e->key, key, key_len + 1);
	return (e);
}

static void		*map_get(t_map *m, char* key)
{
	size_t		index;
	t_list		*iterator;

	index = m->_hash_func(m, key);
	iterator = m->map_array[index]._first;
	while (iterator)
	{
		if (!strcmp(((t_map_elem *)iterator->content)->key, key))
			return (((t_map_elem *)iterator->content)->content);
		iterator = iterator->next;
	}
	return (NULL);
}

static int		map_insert(t_map *m, char* key, void *content, size_t s)
{
	size_t		index;
	t_map_elem	*e;

	index = m->_hash_func(m, key);
	if (!(e = map_elem_new(key, content, s)))
		return (0);
	if (!queue_enqueue_new(&m->map_array[index], e, sizeof(t_map_elem)))
	{
		free(e->key);
		free(e);
		return (0);
	}
	m->n_elem++;
	return (1);
}

static void		*map_insert_and_replace(t_map *m, char* key, void *content, size_t s)
{
	size_t		index;
	t_map_elem	*e;
	t_list		*iterator;
	void		*old_content;

	index = m->_hash_func(m, key);
	iterator = m->map_array[index]._first;
	while (iterator)
	{
		if (!strcmp(((t_map_elem *)iterator->content)->key, key))
		{
			old_content = ((t_map_elem *)iterator->content)->content;
			((t_map_elem *)iterator->content)->content = content;
			((t_map_elem *)iterator->content)->size = s;
			return (old_content);
		}
		iterator = iterator->next;
	}
	if (!(e = map_elem_new(key, content, s)))
		return (NULL);
	if (!queue_enqueue_new(&m->map_array[index], e, sizeof(t_map_elem)))
	{
		free(e->key);
		free(e);
		return (NULL);
	}
	m->n_elem++;
	return (content);
}

static void		*map_extract(t_map *m, char* key)
{
	size_t		index;
	t_list		*iterator;
	t_list		*prev;
	void		*e_content;

	index = m->_hash_func(m, key);
	iterator = m->map_array[index]._first;
	prev = NULL;
	while (iterator)
	{
		if (!strcmp(((t_map_elem *)iterator->content)->key, key))
		{
			if (prev)
				prev->next = iterator->next;
			else
				m->map_array[index]._first = iterator->next;
			e_content = ((t_map_elem *)iterator->content)->content;
			map_elem_del((t_map_elem **)&iterator->content);
			free(iterator);
			return (e_content);
		}
		prev = iterator;
		iterator = iterator->next;
	}
	return (NULL);
}

static void		map_del(t_map *m, char* key)
{
	size_t		index;
	t_list		*iterator;
	t_list		*prev;

	index = m->_hash_func(m, key);
	iterator = m->map_array[index]._first;
	prev = NULL;
	while (iterator)
	{
		if (!strcmp(((t_map_elem *)iterator->content)->key, key))
		{
			if (prev)
				prev->next = iterator->next;
			else
				m->map_array[index]._first = iterator->next;
			map_elem_del_content((t_map_elem **)&iterator->content);
			free(iterator);
			return ;
		}
		prev = iterator;
		iterator = iterator->next;
	}
	return ;
}

static int		map_key_exists(t_map *m, char *key)
{
	size_t		index;
	t_list		*iterator;

	index = m->_hash_func(m, key);
	iterator = m->map_array[index]._first;
	while (iterator)
	{
		if (!strcmp(((t_map_elem *)iterator->content)->key, key))
			return (1);
		iterator = iterator->next;
	}
	return (0);
}

t_map			map_create(size_t (*hash_func)(t_map *, char *), size_t map_array_len)
{
	t_map m;

	m._len = map_array_len > 10 ? map_array_len : DEFAULT_MAP_ARRAY_LEN;
	m.map_array = malloc(m._len * sizeof(t_queue));
	bzero(m.map_array, m._len * sizeof(t_queue));

	m._hash_func = hash_func ? hash_func : default_hash_func;
	m.n_elem = 0;
	m.is_empty = map_is_empty;
	m.insert = map_insert;
	m.insert_replace = map_insert_and_replace;
	m.get = map_get;
	m.extract = map_extract;
	m.del = map_del;
	m.exists = map_key_exists;
	return (m);
}
