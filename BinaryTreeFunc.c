#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

ListData lowestCommonAncestor(BTree* startTree, BTree* tree1, BTree* tree2)
{
	if (tree1 == tree2) {
		puts("Warning : Arguments of trees aren't unique. The LCD is same as arguments...");
		return tree1;
	}

	ListData LCA;
	DLList* path1 = (DLList*)calloc(1, sizeof(DLList));
	DLList* path2 = (DLList*)calloc(1, sizeof(DLList));
	insertDummy(path1);
	insertDummy(path2);

	findTarget = false;
	findPath(startTree, tree1, path1);
	findTarget = false;
	findPath(startTree, tree2, path2);

	LCA = findLCA(path1, path2);
	removeAllList(path1);
	removeAllList(path2);

	return LCA;
}

ListData findLCA(DLList* path1, DLList* path2)
{
	bool existLCD = false;
	path1->current = path1->head;
	path2->current = path2->head;

	while (path1->current->next != NULL && path2->current->next != NULL && path1->current->next->data == path2->current->next->data)
	{
		path1->current = path1->current->next;
		path2->current = path2->current->next;
		existLCD = true;
	}
	if (existLCD)
		return path1->current->data;
	else
		return NULL;
}

void findPath(BTree* startTree, BTree* targetTree, DLList* path)
{
	if (startTree == NULL || findTarget)
		return;

	insertList(path, startTree);

	if (startTree == targetTree)
		findTarget = true;
	
	findPath(startTree->left, targetTree, path);
	findPath(startTree->right, targetTree, path);
	
	if (!findTarget)
		removeList(path);
}

BTree* setBTree(TreeData data)
{
	BTree* newBtree = (BTree*)calloc(1, sizeof(BTree));
	newBtree->data = data;

	return newBtree;
}

void setSubBTree(BTree* rootTree, BTree* leftSubTree, BTree* rightSubTree)
{
	if (rootTree == NULL || leftSubTree == NULL || rightSubTree == NULL) {
		puts("\n\nError : Tree pointer points NULL...\n");
		exit(-1);
	}

	rootTree->left = leftSubTree;
	rootTree->right = rightSubTree;
}

void removeAllList(DLList* plist)
{
	plist->current = plist->head;

	while (plist->current != NULL)
	{
		DLLNode* rnode = plist->current;
		plist->current = plist->current->next;
		free(rnode);
	}
	free(plist);
}

void insertDummy(DLList* plist)
{
	plist->head = (DLLNode*)calloc(1, sizeof(DLLNode));
	plist->current = plist->head;
}

void insertList(DLList* plist, ListData data)
{
	DLLNode* newNode = (DLLNode*)malloc(sizeof(DLLNode));
	plist->current->next = newNode;
	newNode->before = plist->current;
	newNode->next = NULL;
	newNode->data = data;
	plist->current = newNode;
	plist->numberOfNode++;
}

void removeList(DLList* plist)
{
	DLLNode* rnode;
	rnode = plist->current;
	plist->current->before->next = plist->current->next;
	if (plist->current->next != NULL)
		plist->current->next->before = plist->current->before;
	plist->current = plist->current->before;
	plist->numberOfNode--;
}
