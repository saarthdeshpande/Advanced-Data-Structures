/*
 * StackADT.cpp
 *
 *  Created on: 18-Dec-2019
 *      Author: g9
 */

#include "StackADT.h"

StackADT::StackADT() {
	// TODO Auto-generated constructor stub

}

StackADT::~StackADT() {
	// TODO Auto-generated destructor stub
}

bool StackADT::isempty()
{
	return(top.isempty());
}

void StackADT::push(char x)
{
	top.insert(x);
}

char StackADT::pop()
{
	return(top.remove());
}

char StackADT::peep()
{
	return (top.peep1());
}
