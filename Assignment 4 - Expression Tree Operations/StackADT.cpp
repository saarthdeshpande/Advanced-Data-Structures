/*
 * StackADT.cpp
 *
 *  Created on: 05-Feb-2020
 *      Author: g9
 */

#include "StackADT.h"

StackADT::StackADT() {
	// TODO Auto-generated constructor stub
	top = NULL;
}

StackADT::~StackADT() {
	// TODO Auto-generated destructor stub
}

bool StackADT::isempty()
{
	if(top == NULL)
		return 1;
	return 0;
}

void StackADT::push(BNode *x)
{
	StackNode *n = new StackNode;
	n -> data = x;
	n -> next = top;
	top = n;
}

BNode * StackADT::pop()
{
	BNode *returnNode = top -> data;
	StackNode  *topNode;
	topNode = top;
	top = top -> next;
	delete topNode;
	return returnNode;
}

BNode* StackADT::peep()
{
	return top -> data;
}
