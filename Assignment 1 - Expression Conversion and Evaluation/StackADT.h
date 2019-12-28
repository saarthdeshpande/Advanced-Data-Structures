/*
 * StackADT.h
 *
 *  Created on: 18-Dec-2019
 *      Author: g9
 */

#include "ListADT.h"
#ifndef STACKADT_H_
#define STACKADT_H_

class StackADT
{
	ListADT top;
public:
	StackADT();
	void push(char x);
	char pop();
	bool isempty();
	char peep();
	virtual ~StackADT();
};

#endif /* STACKADT_H_ */
