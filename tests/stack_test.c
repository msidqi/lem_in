#include "stacks_queues.h"
#include "test.h"
#include <stdio.h>

void	compare_nums(int a, int b, char *test_name)
{
	if (a == b)
		printf("PASSED: %s\n", test_name);
	else
		printf("FAILED: %s\n", test_name);
}

int main(void)
{
	t_stack s;
	int *content;

	s = stack_create();


	content = malloc(sizeof(int));
	*content = 3;
	s.push(&s, lst_new(content, sizeof(int)));

	compare_nums(*((int *)s._first->content), 3, "_first == 3");

	content = malloc(sizeof(int));
	*content = 4;
	s.push(&s, lst_new(content, sizeof(int)));

	compare_nums(*((int *)s._first->content), 4, "_first == 4");

	content = malloc(sizeof(int));
	*content = 5;
	s.push(&s, lst_new(content, sizeof(int)));

	compare_nums(*((int *)s._first->content), 5, "_first == 5");

	t_list *removed;
	
	removed = s.pop(&s);
	compare_nums(*((int *)removed->content), 5, "5 == 5");
	lst_del_one(&removed);

	removed = s.pop(&s);
	compare_nums(*((int *)removed->content), 4, "4 == 4");
	lst_del_one(&removed);

	removed = s.pop(&s);
	compare_nums(*((int *)removed->content), 3, "3 == 3");
	lst_del_one(&removed);

	return (0);
}
