#include <stdbool.h>
#include <math.h>

#include "tree.h"

#define TOTAL_ITEMS 50

struct queue {
	struct tree_node *q[TOTAL_ITEMS];
	int front;
	int back;
} my_q;

int level, span;

void enqueue(struct tree_node *ptr)
{
	my_q.q[my_q.front++] = ptr;

	if (my_q.front == TOTAL_ITEMS)
		my_q.front = 0;

}


bool onlynulls()
{
	int start = my_q.back;
	int i;

	for (i = start; i < my_q.front; i++) {
		if (i == TOTAL_ITEMS)
			i = 0;
		if (my_q.q[i] != NULL)
			return false;
	}

	if (i == my_q.front) {
		return true;
	}

	return false;

}

bool empty()
{

	if ((my_q.front == my_q.back) || onlynulls()) {
		my_q.front = 0;
		my_q.back = 0;
		return true;
	}
	else
		return false;

}

void dequeue()
{
	int index = my_q.back;
	int max = my_q.front;
	int i, outer_pad, inner_pad;

	if (max < index)
		max += TOTAL_ITEMS;

	outer_pad = span/(int)pow(2, level);
	inner_pad = (2 * outer_pad) + 1;

	for (i = 0; i < outer_pad; i++)
		printf("   ");

	for(; index < max; index++) {
		struct tree_node *ptr = my_q.q[my_q.back++];

		if (my_q.back == TOTAL_ITEMS)
			my_q.back = 0;

		if (ptr != NULL) {
			printf("%2d%c", ptr->val, (ptr->color == RED) ? 'r' : 'b');

			enqueue(ptr->left);
			enqueue(ptr->right);
		} else {
			printf(" - ");
			enqueue(NULL);
			enqueue(NULL);
		}

		for(i = 0; i < inner_pad; i++)
			printf("   ");

	}

	for (i = 0; i < outer_pad; i++)
		printf("   ");

	printf("\n");

}

void pretty_print(struct tree_node *root)
{
	int height = root->height;
	span = pow(2, height) - 1;

	level = 1;

	enqueue(root);
	while(1) {
		if (empty())
			break;
		dequeue();
		level++;
	}
	span = 0;
	level = 0;
	return;
}
