#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tree.h"

extern struct tree_node *rootptr;
 
void swap_colors(struct tree_node *cur)
{
	if (cur->color == RED)
		cur->color = BLACK;
	else
		cur->color = RED;

	if (cur == rootptr)
		cur->color = BLACK;

}

void push_blackness(struct tree_node *cur)
{
	swap_colors(cur);
	swap_colors(cur->left);
	swap_colors(cur->right);
}

int check_two_reds(struct tree_node **cur_ptr, struct tree_node **parent_ptr)
{
	struct tree_node *cur, *left, *right;
	struct tree_node *left_left, *left_right;
	struct tree_node *right_right, *right_left;

	LOG("check two reds\n");
	cur = *cur_ptr;

	left = cur->left;
	right = cur->right;


	if (left) {
		if (left->color == RED) {
			left_left = left->left;
			left_right = left->right;
			if (left_left) {
				if (left_left->color == RED)
					return LEFT_LEFT;
			} else if (left_right) {
				if (left_right->color == RED)
					return LEFT_RIGHT;
			}
		}
	} else if (right) {
		if (right->color == RED) {
			right_right = right->right;
			right_left = right->left;
			if (right_right) {
				if (right_right->color == RED)
					return RIGHT_RIGHT;
			} else if (right_left) {
				if (right_left->color == RED)
					return RIGHT_LEFT;
			}
		}
	}
	return 0;
}

bool uncle_is_red(struct tree_node **cur_ptr, struct tree_node **parent_ptr)
{
	struct tree_node *cur, *child, *uncle;
	struct tree_node *parent;

	LOG("uncle is red\n");

	cur = *cur_ptr;

	parent = *parent_ptr;

	if (cur == parent->left)
		uncle = parent->right;
	else
		uncle = parent->left;

	child = cur->left ? cur->left : cur->right;

	if (child == NULL)
		return false;

	if (uncle)
		if (cur->color == RED && child->color == RED && uncle->color == RED)
			return true;

	return false;
}

void check_properties(struct tree_node **cur_ptr, struct tree_node **parent_ptr)
{
	struct tree_node *cur, *left, *right;
	int rotation;

	LOG("check properties %p\n", *cur_ptr);

	if (*cur_ptr == NULL)
		return;

	check_properties(&(*cur_ptr)->left, cur_ptr);
	check_properties(&(*cur_ptr)->right, cur_ptr);

	cur = *cur_ptr;

	left = cur->left;
	right = cur->right;

	if (left == NULL && right == NULL)
		return;

	if (cur != rootptr) {
		if(uncle_is_red(cur_ptr, parent_ptr)) {
			push_blackness(*parent_ptr);
			return;
		}
	}

	rotation = check_two_reds(cur_ptr, parent_ptr);

	switch (rotation) {
		case LEFT_LEFT: {
			rotate_right_2(cur_ptr, parent_ptr);
			break;
		}
		case LEFT_RIGHT: {
			rotate_right_1(cur_ptr, parent_ptr);
			break;
		}
		case RIGHT_RIGHT: {
			rotate_left_2(cur_ptr, parent_ptr);
			break;
		}
		case RIGHT_LEFT: {
			rotate_left_1(cur_ptr, parent_ptr);
			break;
		}
		case 0: {
		 	LOG(" no rotation\n");
			break;
		}
	}


	return;
}
