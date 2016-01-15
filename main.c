
#include "tree.h"

struct tree_node *rootptr;

void insert(struct tree_node **ptr, int input_val)
{
	if (*ptr == NULL) {
		*ptr = (struct tree_node *)malloc((sizeof(struct tree_node)));
		(*ptr)->val = input_val;
		(*ptr)->left = NULL;
		(*ptr)->right = NULL;
		(*ptr)->height = -1;
		(*ptr)->color = RED;
		LOG("node %p val %d\n", *ptr, (*ptr)->val);
		return;
	}

	if (input_val < (*ptr)->val)
		insert(&(*ptr)->left, input_val);
	else if (input_val > (*ptr)->val)
		insert(&(*ptr)->right, input_val);

	return;
}

void free_tree(struct tree_node *ptr)
{
	if (ptr == NULL)
		return;

	free_tree(ptr->left);
	free_tree(ptr->right);


	LOG("free ptr %p data %d\n", ptr, ptr->val);
	free(ptr);
	return;
}

int main(int argc, char *argv[])
{
	int input_val;

	while(1) {
		printf("please enter a number, or 0 to exit\n");

		scanf("%d",&input_val);

		if (input_val == 0)
			break;
		else {
			if (rootptr == NULL) {
				rootptr = (struct tree_node*)malloc(sizeof(*rootptr));
				rootptr->val = input_val;
				rootptr->left = NULL;
				rootptr->right = NULL;
				rootptr->height = -1;
				rootptr->color = BLACK;
			}
			else {
				insert(&rootptr, input_val);
				check_properties(&rootptr, NULL);
				height(&rootptr, NULL);
				pretty_print(rootptr);
			}

		}

	}
	free_tree(rootptr);
	return 0;
}
