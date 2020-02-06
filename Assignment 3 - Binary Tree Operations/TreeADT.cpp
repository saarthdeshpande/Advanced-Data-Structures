/*
 * TreeADT.cpp
 *
 *  Created on: 06-Feb-2020
 *      Author: saarth
 */

#include "TreeADT.h"
#include <iostream>
using namespace std;

TreeADT::TreeADT() {
	// TODO Auto-generated constructor stub
	root = NULL;
}

TreeADT::~TreeADT() {
	// TODO Auto-generated destructor stub
}

BNode* TreeADT::newNode(int v)
{
    BNode *temp = new BNode;
    temp -> left = temp -> right = NULL;
    temp -> info = v;
    return temp;
};

BNode* TreeADT::getRootNode()
{
	return root;
}

void TreeADT::insertNode(int info)
{
	int resp;
	BNode *n = newNode(info);
	if(root == NULL)
		root = n;
	else
	{
		BNode *T = root;
		int flag = 0;
		do
		{
			cout << "\nNode to Insert: " << info << endl << "Current Node: " << T -> info;
			cout << "\n1. Insert at Left\n2. Insert at Right\nYour Choice: ";
			cin >> resp;
			switch(resp)
			{
				case 1: if(T -> left != NULL)
							T = T -> left;
						else
						{
							T -> left = n;
							flag = 1;
						}
						break;
				case 2: if(T -> right != NULL)
							T = T -> right;
						else
						{
							T -> right = n;
							flag = 1;
						}
						break;
				default: cout << "\nPlease enter a valid response.\n";
			}
		}while(flag != 1);
	}
}

void TreeADT::preOrder(BNode* T)
{
	if(T != NULL)
	{
		cout << T -> info << " ";
		preOrder(T -> left);
		preOrder(T -> right);
	}
}

void TreeADT::inOrder(BNode* T)
{
	if(T != NULL)
	{
		inOrder(T -> left);
		cout << T -> info << " ";
		inOrder(T -> right);
	}
}

void TreeADT::postOrder(BNode* T)
{
	if(T != NULL)
	{
		postOrder(T -> left);
		postOrder(T -> right);
		cout << T -> info << " ";
	}
}

void TreeADT::display(BNode* T)
{
	int resp;
	cout << "\n1. Pre-Order Traversal\n2. In-Order Traversal\n3. Post-Order Traversal\nYour Choice: ";
	cin >> resp;
	switch(resp)
	{
		case 1: cout << "\nPre-Order Traversal: ";
				preOrder(T);
				cout << endl;
				break;
		case 2: cout << "\nIn-Order Traversal: ";
				inOrder(T);
				cout << endl;
				break;
		case 3: cout << "\nPost-Order Traversal: ";
				postOrder(T);
				cout << endl;
				break;
		default: cout << "\nPlease enter a valid response.\n";
	}
}

int TreeADT::depth(BNode *T)
{
	if(T == NULL)
		return 0;
	else
	{
		// compute the depth of each subtree
		int leftDepth = depth(T -> left);
		int rightDepth = depth(T -> right);

		// use the larger one
		if (leftDepth > rightDepth)
			return(leftDepth + 1);
		else return(rightDepth + 1);
	}
}

void TreeADT::displayLeafNodes(BNode *T)
{
	if(T == NULL)
		return;

	if(T -> left == NULL && T -> right == NULL)		// if node is leaf node, print its data
	{
		cout << T -> info << " ";
		return;
	}

	if(T -> left != NULL)	// if left child exists, check for leaf recursively
	   displayLeafNodes(T -> left);

	if (T -> right != NULL)			// if right child exists, check for leaf recursively
	   displayLeafNodes(T -> right);
}

BNode* TreeADT::createCopy(BNode* T)
{
	BNode* temp = NULL;
	if(T != NULL)
	{
		temp = newNode(T -> info);
		temp -> left = createCopy(T -> left);
		temp -> right = createCopy(T -> right);
	}
	return temp;
}

void TreeADT::copy(TreeADT T)
{
	root = createCopy(T.root);
}
