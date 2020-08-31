#include "hash_map.h"
#include <stdio.h>

void	compare_str(char *a, char *b, char *test_name)
{
	if (!strcmp(a, b))
		printf("PASSED: %s\n", test_name);
	else
		printf("FAILED: %s\n", test_name);
}

void	compare_nums(int a, int b, char *test_name)
{
	if (a == b)
		printf("PASSED: %s\n", test_name);
	else
		printf("FAILED: %s\n", test_name);
}

void print_element(t_list *l)
{
    printf("    key (%s) is full | (%s)\n",
    ((t_map_elem *)l->content)->key,
    (char *)((t_map_elem *)l->content)->content);
}

int main(void)
{
    t_map m = map_create(NULL, 0);
    char *string[3];

    // string[0] = malloc(sizeof(char) * 12);
    // strcpy(string[0], "hello world");
    // string[1] = malloc(sizeof(char) * 12);
    // strcpy(string[1], "hello there");
    string[2] = malloc(sizeof(char) * 15);
    strcpy(string[2], "hello everyone");

    m.insert(&m, "first_key", string[0], strlen(string[1]) + 1);
    m.insert(&m, "second_key", string[1], strlen(string[1]) + 1);
    m.insert(&m, "third_key", string[2], strlen(string[2] + 1));

    compare_str((char *)m.get(&m, "first_key"), string[0], "first key");
    compare_str((char *)m.get(&m, "second_key"), string[1], "second key");
    compare_str((char *)m.get(&m, "third_key"), string[2], "third key");
    
    m.del(&m, "first_key");
    m.del(&m, "second_key");
    m.del(&m, "third_key");
    
    printf("key: (%s) | value: (%s)\n",
    "third_key", (char *)m.get(&m, "third_key"));

    size_t map_array_len = 0;
    for (int i = 0; i < m._len; i++)
        map_array_len++;

    compare_nums(map_array_len, m._len, "map_array length");
    compare_nums(m.n_elem, 3, "number of inserted elements");
    free(m.map_array);
    return (0);
}
