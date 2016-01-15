#include "tree.h"

extern struct tree_node *rootptr;

void rotate_left_2(struct tree_node **cur_ptr, struct tree_node **parent_ptr)
{
	struct tree_node *cur, *right, *right_left;
	cur = *cur_ptr;
	right = cur->right;
	right_left = right->left;
	int temp;

	LOG("rotate left 2\n");
	{
		cur->right = right_left;
		right->left = cur;
	}

	if (parent_ptr == NULL)
		rootptr = right;
	else {
		struct tree_node* parent = *parent_ptr;
		if (parent->left == cur)
			parent->left = right;
		else
			parent->right = right;

	}

	temp = right->color;
	right->color = cur->color;
	cur->color = temp;
}

void rotate_left_1(struct tree_node **cur_ptr, struct tree_node **parent)
{
	struct tree_node *cur, *right, *right_left;
	cur = *cur_ptr;
	right = cur->right;
	right_left = right->left;

	LOG("rotate left 1\n");

	{
		cur->right = right_left;
		right->left = right_left->right;
		right_left->right = right;
	}

	rotate_left_2(cur_ptr, parent);

}

void rotate_right_2(struct tree_node **cur_ptr, struct tree_node **parent_ptr)
{
	struct tree_node *cur;
	struct tree_node *left, *left_right;
	cur = *cur_ptr;
	left = cur->left;
	left_right = left->right;
	int temp;

	LOG("rotate right 2\n");

	{
		cur->left = left_right;
		left->right = cur;
	}

	if (parent_ptr == NULL)
		rootptr = left;
	else {
		struct tree_node *parent = *parent_ptr;
		if (parent->left == cur)
			parent->left = left;
		else
			parent->right = left;
	}

	temp = left->color;
	left->color = cur->color;
	cur->color = temp;

	return;
}

void rotate_right_1(struct tree_node **cur_ptr, struct tree_node **parent)
{
	struct tree_node *cur, *left, *left_right;
	cur = *cur_ptr;
	left = cur->left;
	left_right = left->right;

	LOG("rotate right 1\n");

	{
		left->right = left_right->left;
		left_right->left = left;
		cur->left = left_right;
	}

	rotate_right_2(cur_ptr, parent);
}

#if 0
static int findtype(struct tree_node *cur)
{
	if (cur->left_height > cur->right_height) {
		struct tree_node *left = cur->left;
		if (left->left_height > left->right_height)
			return LEFT_LEFT;
		else
			return LEFT_RIGHT;
	} else {
		struct tree_node *right = cur->right;
		if (right->left_height > right->right_height)
			return RIGHT_LEFT;
		else
			return RIGHT_RIGHT;
	}

}

void rotate(struct tree_node **cur, struct tree_node **parent)
{
	int type;

	type = findtype(*cur);

	switch(type) {
		case LEFT_LEFT: {
			rotate_right_2(cur, parent);
			break;
		}
		case LEFT_RIGHT:{
			rotate_right_1(cur, parent);
			break;
		}
		case RIGHT_RIGHT: {
			rotate_left_2(cur, parent);
			break;
		}
		case RIGHT_LEFT:{
			rotate_left_1(cur, parent);
			break;
		}
	}
	return;
}
#endif
