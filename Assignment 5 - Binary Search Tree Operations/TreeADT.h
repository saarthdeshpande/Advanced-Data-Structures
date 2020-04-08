/*
 * TreeADT.h
 *
 *  Created on: 07-Feb-2020
 *      Author: g9
 */

#ifndef TREEADT_H_
#define TREEADT_H_

struct BNode
{
	int info;
	struct BNode *left ;
	struct BNode *right;
};

class TreeADT {
	BNode *root;
public:
	TreeADT();
	BNode* newNode(int);
	BNode* getRootNode();
	void recursiveInsertion(BNode*,int);
	void nonRecursiveInsertion(int);
	BNode* recursiveDelete(BNode*,int);
	void nonRecursiveDelete(int);
	void display(BNode*);
	void preOrder(BNode*);
	void inOrder(BNode*);
	void postOrder(BNode*);
	void recursiveMirror(BNode*);
	void nonRecursiveMirror();
	bool recursiveSearch(BNode*,int);
	bool nonRecursiveSearch(int);
	int depth(BNode*);
	void printLevelOrder(BNode*);
	virtual ~TreeADT();
};

#endif /* TREEADT_H_ */
