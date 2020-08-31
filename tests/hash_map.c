#include "hash_map.h"
#include <stdio.h>

void print_element(t_list *l)
{
    printf("    key (%s) is full | (%s)\n",
    ((t_map_elem *)l->content)->key,
    (char *)((t_map_elem *)l->content)->content);
}

int main(void)
{
    size_t map_array_len = 0;
    t_map m = map_create(NULL, 0);
    char *string[2];
    char str[] = "third_key value";
    
    string[0] = malloc(sizeof(char) * 11);
    strcpy(string[0], "hello world");
    string[1] = "second_key value";

    m.insert(&m, "first_key", string[0], strlen(string[1]) + 1);

    m.insert(&m, "second_key", string[1], strlen(string[1]) + 1);

    m.insert(&m, "second_key", str, sizeof(str));

    for (int i = 0; i < m._len; i++)
    {
        map_array_len++;
        if (!queue_is_empty(&m.map_array[i]))
        {
            printf("index %d : \n", i);
            lst_iter(m.map_array[i]._first, print_element);
        }
    }
    printf("-----------------\n"
    "map_array_len %zu == %zu | number of inserted elements %zu\n",
    map_array_len, m._len, m.n_elem);
    return (0);
}