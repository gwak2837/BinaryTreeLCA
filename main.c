#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

int main()
{
	BTree* t1 = setBTree(20);
	BTree* t2 = setBTree(8);
	BTree* t3 = setBTree(22);
	BTree* t4 = setBTree(4);
	BTree* t5 = setBTree(12);
	BTree* t6 = setBTree(10);
	BTree* t7 = setBTree(14);

	setSubBTree(t1, t2, t3);
	setSubBTree(t2, t4, t5);
	setSubBTree(t5, t6, t7);

	printf("LCA of %d and %d = %d\n\n", t6->data, t7->data, lowestCommonAncestor(t1, t6, t7)->data);
	printf("LCA of %d and %d = %d\n\n", t7->data, t2->data, lowestCommonAncestor(t1, t7, t2)->data);
	printf("LCA of %d and %d = %d\n\n", t6->data, t3->data, lowestCommonAncestor(t1, t6, t3)->data);

	return 0;
}
