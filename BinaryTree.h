#pragma once
#ifndef __BINARY_TREE__
#define __BINARY_TREE__
#include <stdbool.h>

// Because of recursive function
bool findTarget;

typedef int TreeData;
typedef struct _binaryTree
{
	TreeData data;
	struct _binaryTree* left, * right;
} BTree;

typedef BTree* ListData;
typedef struct _doubleLinkedListNode
{
	ListData data;
	struct _doubleLinkedListNode* before, *next;
} DLLNode;

typedef struct _doubleLinkedList
{
	DLLNode* head;
	DLLNode* current;
	int numberOfNode;
} DLList;

// Finding LCD Functions
ListData lowestCommonAncestor(BTree* startTree, BTree* tree1, BTree* tree2);
ListData findLCA(DLList* path1, DLList* path2);
void findPath(BTree* startTree, BTree* tree, DLList* path);

// Binary Tree Functions
BTree* setBTree(TreeData data);
void setSubBTree(BTree* rootTree, BTree* leftSubTree, BTree* rightSubTree);

// Dummy Double Linked List Functions
void removeAllList(DLList* plist);
void insertDummy(DLList* plist);
void insertList(DLList* plist, ListData data);
void removeList(DLList* plist);

#endif
