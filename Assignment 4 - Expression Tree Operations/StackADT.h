/*
 * StackADT.h
 *
 *  Created on: 05-Feb-2020
 *      Author: g9
 */

#ifndef STACKADT_H_
#define STACKADT_H_

#include<iostream>

struct BNode
{
	char info;
	struct BNode *left ;
	struct BNode *right;
};

struct StackNode
{
	BNode *data ;
	StackNode *next ;
};

class StackADT
{
	StackNode *top;
public:
	StackADT();
	virtual ~StackADT();
	BNode * pop();
	void push(BNode *);
	BNode* peep();
	bool isempty();
};

#endif /* STACKADT_H_ */
