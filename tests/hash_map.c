#include "hash_map.h"
#include <stdio.h>

int main(void)
{
    char str[] = "hello world";
    int m_real_len = 0;
    t_map m = map_create(NULL, 0);

    char *m_string = malloc(sizeof(char) * 11);
    strcpy(m_string, "hello there");
    
    m.map[10].content = m_string;
    m.map[10].size = sizeof(str);

    // m.map_array[10].enqueue_new(&m.map_array[10], m_string, sizeof(str));

    m.insert(&m, "first_key", str, sizeof(str));

    int a = 12312;
    m.insert(&m, "second_key", &a, sizeof(a));

    for (int i = 0; i < m._len; i++)
    {
        m_real_len++;
        // printf("map[key] addr %p\n", ((char **)m.map)[i]);
        if (m.map[i].content)
            printf("key %d is full | %s\n", i, (char *)m.map[i].content);
    }    
    printf("m_real_len %d == %zu\n", m_real_len, m._len);
    return (0);
}