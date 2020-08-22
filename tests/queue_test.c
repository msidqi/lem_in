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
	t_queue q;
	int *content;

	q = queue_create();


	content = malloc(sizeof(int));
	*content = 3;
	q.enqueue(&q, lst_new(content, sizeof(int)));

	compare_nums(*((int *)q._first->content), 3, "first == 3");
	compare_nums(*((int *)q._last->content), 3, "last == 3");

	content = malloc(sizeof(int));
	*content = 4;
	q.enqueue(&q, lst_new(content, sizeof(int)));

	compare_nums(*((int *)q._first->content), 3, "first == 3");
	compare_nums(*((int *)q._last->content), 4, "last == 4");
	
	content = malloc(sizeof(int));
	*content = 5;
	q.enqueue(&q, lst_new(content, sizeof(int)));

	t_list *removed;
	
	removed = q.dequeue(&q);
	compare_nums(*((int *)removed->content), 3, "3 == 3");
	lst_del_one(&removed);

	removed = q.dequeue(&q);
	compare_nums(*((int *)removed->content), 4, "4 == 4");
	lst_del_one(&removed);

	removed = q.dequeue(&q);
	compare_nums(*((int *)removed->content), 5, "5 == 5");
	lst_del_one(&removed);

	return(0);
}
