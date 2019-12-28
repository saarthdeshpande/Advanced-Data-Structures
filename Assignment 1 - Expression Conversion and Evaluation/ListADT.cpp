/*
 * ListADT.cpp
 *
 *  Created on: 18-Dec-2019
 *      Author: g9
 */

#include "ListADT.h"
#include<iostream>

Node::Node()
{
	val = 0;
	next = NULL;
}

ListADT::ListADT()
{
	head = NULL;
}

ListADT::~ListADT() {
	// TODO Auto-generated destructor stub
}

bool ListADT::isempty()
{
	if(head == NULL)
		return 1;
	return  0;
}

void ListADT::insert(char x)
{
	Node *n = new Node;
	n -> val = x;
	n -> next = head;
	head = n;
}

int ListADT::numberOfNodes()
{
	Node *temp = head;
	int count = 0;
	while(temp != NULL)
	{
		temp = temp -> next;
		count += 1;
	}
	return count;
}

void ListADT::insertInMiddle(char x)
{
	Node *temp = head;
	int middlePosition = numberOfNodes()/2;
	int iterator = 0;
	while((temp != NULL)&&(iterator < middlePosition))
		temp = temp -> next;
	Node *n = new Node;
	n -> val = x;
	n -> next = temp -> next;
	temp -> next = n;
}

void ListADT::insertAtEnd(char x)
{
	Node *n = new Node;
	n -> val = x;
	if(isempty())
		head = n;
	else
	{
		Node *iteratorNode = head;
		while(iteratorNode -> next != NULL)
			iteratorNode = iteratorNode -> next;
		iteratorNode -> next = n;
	}
}

char ListADT::remove()
{
	Node *temp = head;
	char t = temp -> val;
	head = head -> next;
	delete(temp);
	return t;
}

void ListADT::removeInMiddle()
{
	Node *temp = head;
	int middlePosition = numberOfNodes()/2;
	int iterator = 0;
	while((temp != NULL)&&(iterator < middlePosition))
		temp = temp -> next;
	if(temp == NULL)
		std::cout << "No Nodes to Delete!";
	else
	{
		Node *temp2 = temp -> next;
		temp -> next = temp2 -> next;
		delete(temp2);
	}
}

char ListADT::removeAtEnd()
{
	Node *lastElement = head;
	while(lastElement -> next -> next != NULL)
		lastElement = lastElement -> next;
	Node *secondLastElement = lastElement;
	lastElement = lastElement -> next;
	char x = lastElement -> val;
	secondLastElement -> next = 0;
	delete(lastElement);
	return x;
}

char ListADT::peep1()
{
	return (head -> val);
}
