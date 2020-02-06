/*
 * TreeADT.cpp
 *
 *  Created on: 05-Feb-2020
 *      Author: g9
 */

#include "TreeADT.h"
#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^')
        return true;
    return false;
}

TreeADT::TreeADT() {
	// TODO Auto-generated constructor stub
	root = NULL;
}

TreeADT::~TreeADT() {
	// TODO Auto-generated destructor stub
}

BNode* TreeADT::newNode(char v)
{
    BNode *temp = new BNode;
    temp -> left = temp -> right = NULL;
    temp -> info = v;
    return temp;
};

void TreeADT::createTree(char expression[])
{
	if(!isOperator(expression[0]))	// Check if post-fix
	{
		StackADT st;
		BNode *t, *t1, *t2;
		for(int i = 0;i < strlen(expression);i++)		// Traverse through every character of input expression
		{
			if (!isOperator(expression[i]))	// If operand, push to stack
			{
				t = newNode(expression[i]);
				st.push(t);
			}
			else // operator
			{
				t = newNode(expression[i]);

				// Pop two top nodes
				t1 = st.pop();
				t2 = st.pop();

				//  make them children
				t -> right = t1;
				t -> left = t2;

				st.push(t);	// Add this subexpression to stack
			}
		}
		root = st.pop();	//  only element will be root of expression tree
		cout << "\nTree created Successfully!\n";
	}
	else
	{
		StackADT st;
		BNode *t, *t1, *t2;
		std::reverse(expression,expression + strlen(expression));
		for(int i = 0;i < strlen(expression);i++)		// Traverse through every character of input expression
		{
			if (!isOperator(expression[i]))	// If operand, push to stack
			{
				t = newNode(expression[i]);
				st.push(t);
			}
			else // operator
			{
				t = newNode(expression[i]);

				// Pop two top nodes
				t1 = st.pop();
				t2 = st.pop();

				//  make them children
				t -> left = t1;
				t -> right = t2;

				st.push(t);	// Add this subexpression to stack
			}
		}
		root = st.pop();	//  only element will be root of expression tree
		cout << "\nTree created Successfully!\n";
	}
}

void TreeADT::RecursivePreOrder(BNode *T)
{
	if(T != NULL)
	{
		cout << T -> info;
		RecursivePreOrder(T -> left);
		RecursivePreOrder(T -> right);
	}
}

void TreeADT::RecursiveInOrder(BNode *T)
{
	if(T != NULL)
	{
		RecursiveInOrder(T -> left);
		cout << T -> info;
		RecursiveInOrder(T -> right);
	}
}

void TreeADT::RecursivePostOrder(BNode *T)
{
	if(T != NULL)
	{
		RecursivePostOrder(T -> left);
		RecursivePostOrder(T -> right);
		cout << T -> info;
	}
}

void TreeADT::NonRecursivePreOrder(BNode *T)
{
	if(T == NULL)
	{
		cout << "\nTree is Empty.\n";
		return;
	}
	StackADT s;
	s.push(T);
	do
	{
		BNode *p = s.pop();
		while(p != NULL)
		{
			cout << p -> info;
			if(p -> right != NULL)
				s.push(p -> right);
			p = p -> left;
		}
	}while(!s.isempty());
}

void TreeADT::NonRecursivePostOrder(BNode *T)
{
	if(T == NULL)
	{
		cout << "\nTree is Empty.\n";
		return;
	}
	StackADT s1, s2;	// Create two stacks
	s1.push(T);		// push root to first stack
	BNode* node;
	while (!s1.isempty()) 	// Run while first stack is not empty
	{
		node = s1.pop();	// Pop an item from s1 and push it to s2
		s2.push(node);
		if (node -> left)		// Push left and right children of removed item to s1
			s1.push(node -> left);
		if (node -> right)
			s1.push(node -> right);
	}
	while (!s2.isempty())	// Print all elements of second stack
	{
		node = s2.pop();
		cout << node -> info;
	}
}

void TreeADT::NonRecursiveInOrder(BNode *T)
{
	StackADT s;
	while (T != NULL || !s.isempty())
	{
		while (T !=  NULL)	// Reach the left most Node
		{
			s.push(T);
			T = T -> left;
		}
		T = s.pop();		 // T must be NULL at this point
		cout << T -> info;
		T = T -> right;		// Visited left subtree and node; now visit right
	}
}

BNode* TreeADT::getRootNode()
{
	return root;
}
