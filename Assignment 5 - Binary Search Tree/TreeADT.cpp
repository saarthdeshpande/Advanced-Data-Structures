/*
 * TreeADT.cpp
 *
 *  Created on: 07-Feb-2020
 *      Author: g9
 */

#include "TreeADT.h"
#include <iostream>
using namespace std;
#include <stack>

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
}

void TreeADT::recursiveMirror(BNode* T)
{
	if(T == NULL)
		return;
	BNode *temp;
	// process subtrees
	recursiveMirror(T -> left);
	recursiveMirror(T -> right);

	// swap pointers in this node
	temp = T -> left;
	T -> left = T -> right;
	T -> right = temp;
}

void TreeADT::nonRecursiveMirror()
{
	if (!root)
			return;

		stack<BNode*> s;
		s.push(root);
		while(!s.empty())
		{
			BNode *current = s.top();
			s.pop();

			// Swap the children

			BNode *temp = current->right;
			current->right = current->left;
			current->left = temp;

			// Push the children on the stack

			if (current->right)
				s.push(current->right);

			if (current->left)
				s.push(current->left);
		}
}

bool TreeADT::recursiveSearch(BNode* T,int key)
{
	if(T == NULL)
		return 0;
	else if(T -> info == key)
		return 1;
	else if(T -> info < key)
		recursiveSearch(T -> right,key);
	else if(T -> info > key)
		recursiveSearch(T -> left, key);
}

BNode* minValueNode(BNode *T)
{
	BNode *current = T;
	while(current && current -> left != NULL)	// traverse till leftmost subtree for minimum value node
		current = current -> left;
	return current;
}

BNode* TreeADT::recursiveDelete(BNode *T, int key)
{
	if(T == NULL)
	{
		cout << "\nNode Doesn't Exist!\n";
		return T;
	}
	if(key < T -> info)
		T -> left = recursiveDelete(T -> left, key);
	else if(key > T -> info)
		T -> right = recursiveDelete(T -> right, key);
	else
	{
		// only one child or no child
		if(T -> left == NULL)
		{
			BNode *temp = T -> right;
			delete T;
			return temp;
		}
		else if(T -> right == NULL)
		{
			BNode* temp = T -> left;
			delete T;
			return temp;
		}

		// node with two children: Get the inorder successor (smallest in the right subtree)

		BNode *temp = minValueNode(T -> right);
		T -> info = temp -> info;	// Copy the inorder successor's content to this node
		T -> right = recursiveDelete(T -> right, temp -> info);	// Delete the inorder successor
	}
	root = T;
	return T;
}

void TreeADT::nonRecursiveDelete(int value)
{
	if (root == NULL) {
	           cout << "There are no nodes in this Binary Search Tree";
	        } else {

	            BNode* currentNode = root;
	            BNode* parentNode = NULL;

	            while (true) {

	                if (value > currentNode -> info) {

	                    if (currentNode -> right != NULL) {

	                        parentNode = currentNode;
	                        currentNode = currentNode -> right;
	                    } else {

	                        cout << "No Node is present with this value";
	                        break;
	                    }
	                } else if (value < currentNode -> info) {

	                    if (currentNode -> left != NULL) {

	                        parentNode = currentNode;
	                        currentNode = currentNode -> left;
	                    } else {

	                        cout << "No Node is present with this value";
	                        break;
	                    }
	                } else {

	                    if (currentNode -> left == NULL && currentNode -> right == NULL) {
	                        if (parentNode == NULL) {
	                            root = NULL;
	                        } else if (parentNode -> left -> info == currentNode -> info) {

	                            parentNode -> left = NULL;
	                        } else {
	                            parentNode -> right = NULL;
	                        }
	                    } else if (currentNode -> left == NULL) {
	                        if (parentNode == NULL) {
	                            root = currentNode -> right;
	                        } else if (parentNode -> left -> info == currentNode -> info) {

	                            parentNode -> left = currentNode -> right;
	                        } else {
	                            parentNode -> right = currentNode -> right;
	                        }
	                    } else if (currentNode -> right == NULL) {
	                        if (parentNode == NULL) {
	                            root = currentNode -> left;
	                        } else if (parentNode -> left -> info == currentNode -> info) {

	                            parentNode -> left = currentNode -> left;
	                        } else {
	                            parentNode -> right = currentNode -> left;
	                        }
	                    } else {
	                        int successorNodeValue = minValueNode(currentNode -> right) -> info;
	                        delete(minValueNode(currentNode -> right));
	                        currentNode -> info = successorNodeValue;
	                    }
	                }
	            }
	        }
}

bool TreeADT::nonRecursiveSearch(int key)
{
	BNode *temp = root;
	while(temp != NULL)
	{
		if(temp -> info == key)
			return 1;
		else if(temp -> info > key)
			temp = temp -> left;
		else if(temp -> info < key)
			temp = temp -> right;
	}
	return 0;
}

BNode* TreeADT::getRootNode()
{
	return root;
}

void TreeADT::preOrder(BNode *T)
{
	if(T != NULL)
	{
		cout << T -> info << " ";
		preOrder(T -> left);
		preOrder(T -> right);
	}
}

void TreeADT::inOrder(BNode *T)
{
	if(T != NULL)
	{
		inOrder(T -> left);
		cout << T -> info << " ";
		inOrder(T -> right);
	}
}

void TreeADT::postOrder(BNode *T)
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

void TreeADT::recursiveInsertion(BNode *T,int info)
{
	if(T == NULL)
		T = newNode(info);
	else
		recursiveInsertion((info < T -> info)? T -> left : T -> right, info);
}

void TreeADT::nonRecursiveInsertion(int info)
{
	BNode *ptr = root, *PrevLoc = NULL;
	if(root == NULL)
	{
		root = newNode(info);
		return;
	}
	while(1)
	{
	   PrevLoc = ptr;
	   if(info < ptr -> info)
		  ptr = ptr -> left;
	   else
		  ptr = ptr -> right;
	   if(ptr == NULL)
		   break;
	}
	if(info < PrevLoc -> info)
		 PrevLoc -> left = newNode(info);
	else
		 PrevLoc -> right = newNode(info);
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

void printGivenLevel(BNode* T,int level)
{
    if (T == NULL)
        return;
    if (level == 1)
        cout << T -> info << " ";
    else if (level > 1)
    {
        printGivenLevel(T->left, level-1);
        printGivenLevel(T->right, level-1);
    }
}

void TreeADT::printLevelOrder(BNode* T)
{
    int h = depth(T);
    int i;
    for (i = 1; i <= h; i++)
        printGivenLevel(T, i);
}
