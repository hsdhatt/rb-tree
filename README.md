# rb-tree
rb tree implemented in C

##RB tree properties

1. root is always black
2. A red node will have only black children

##The rules to be checked are:
1. if cur, child and uncle are red.
	2.  push blackness from grandparent to grandparent's children.
	3.  What this means is, swap colors of each of the three nodes.
2. if there are two reds, and uncle is not red,rotate accordingly:
	3. if left is red and left->left is red
	  * rotate right and swap colors of cur and left->left
	5. if left is red and left->right is red
	  * rotate right twice and swap colors of cur and left->right
	7. if right is red and right->right is red
	  * rotate left and swap colors of cur and right->right
	9. if right is red and right->left is red
	  * rotate left twice and swap colors of cur and right->left

   
