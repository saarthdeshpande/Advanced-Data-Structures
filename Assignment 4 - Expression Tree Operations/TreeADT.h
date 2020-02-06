/*
 * TreeADT.h
 *
 *  Created on: 05-Feb-2020
 *      Author: g9
 */

#ifndef TREEADT_H_
#define TREEADT_H_

#include "StackADT.h"


class TreeADT
{
	BNode *root;
public:
	TreeADT();
	BNode* newNode(char);
	BNode* getRootNode();
	void createTree(char[]);
	void RecursivePreOrder(BNode*);
	void NonRecursivePreOrder(BNode*);
	void RecursivePostOrder(BNode*);
	void NonRecursivePostOrder(BNode*);
	void RecursiveInOrder(BNode*);
	void NonRecursiveInOrder(BNode*);
	virtual ~TreeADT();
};

#endif /* TREEADT_H_ */
