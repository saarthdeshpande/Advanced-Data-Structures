/*
 * EvaluationStack.h
 *
 *  Created on: 25-Dec-2019
 *      Author: saarth
 */

#ifndef EVALUATIONSTACK_H_
#define EVALUATIONSTACK_H_

class node
{
	double val;
	node *next;
public:
	friend class EvaluationStack;
};

class EvaluationStack {
	node *head;
public:
	EvaluationStack();
	void push(int);
	double pop();
	double peep();
	bool isempty();
	virtual ~EvaluationStack();
};

#endif /* EVALUATIONSTACK_H_ */
