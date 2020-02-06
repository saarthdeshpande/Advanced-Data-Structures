/*
 * TreeADT.h
 *
 *  Created on: 05-Feb-2020
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

class TreeADT
{
	BNode *root;
public:
	TreeADT();
	BNode* newNode(int);
	BNode* getRootNode();
	void insertNode(int);
	void display(BNode*);
	void preOrder(BNode*);
	void inOrder(BNode*);
	void postOrder(BNode*);
	int depth(BNode*);
	BNode* createCopy(BNode*);
	void copy(TreeADT);
	void displayLeafNodes(BNode*);
	virtual ~TreeADT();
};

#endif /* TREEADT_H_ */
