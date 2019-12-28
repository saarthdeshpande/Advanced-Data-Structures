/*
 * EvaluationStack.cpp
 *
 *  Created on: 25-Dec-2019
 *      Author: saarth
 */

#include<iostream>
#include "EvaluationStack.h"

EvaluationStack::EvaluationStack() {
	// TODO Auto-generated constructor stub
	head = NULL;

}

EvaluationStack::~EvaluationStack() {
	// TODO Auto-generated destructor stub
}

void EvaluationStack::push(int x){
	node *n = new node;
	n -> val = x;
	n -> next = head;
	head = n;
}

double EvaluationStack::pop()
{
	node *temp = head;
	double t = temp -> val;
	head = head -> next;
	delete(temp);
	return t;
}

bool EvaluationStack::isempty()
{
	if(head == NULL)
			return 1;
	return 0;
}

double EvaluationStack::peep()
{
	return (head -> val);
}
