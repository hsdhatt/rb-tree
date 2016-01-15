#include <stdio.h>
#include <stdlib.h>

#define LOG_ENABLE 0x0

#define BLACK	0x1
#define RED	0x2

struct tree_node {
	int val;
	struct tree_node* left;
	struct tree_node* right;
	int height;
	int color;
};

#define LEFT_LEFT	0x1
#define LEFT_RIGHT	0x2
#define RIGHT_RIGHT	0x3
#define RIGHT_LEFT	0x4

#define LOG(fmt, args...)\
	do {\
		if(LOG_ENABLE)\
			printf(fmt, ##args);\
	} while(0)

void rotate(struct tree_node **cur, struct tree_node **parent_ptr);
int height(struct tree_node **cur, struct tree_node **parent_ptr);
void rotate_right_1(struct tree_node **cur, struct tree_node **parent_ptr);
void rotate_right_2(struct tree_node **cur, struct tree_node **parent_ptr);
void rotate_left_1(struct tree_node **cur, struct tree_node **parent_ptr);
void rotate_left_2(struct tree_node **cur, struct tree_node **parent_ptr);
void check_properties(struct tree_node **cur, struct tree_node **parent_ptr);
void pretty_print(struct tree_node *root);
