/*
 * ListADT.h
 *
 *  Created on: 18-Dec-2019
 *      Author: g9
 */

#ifndef LISTADT_H_
#define LISTADT_H_

class Node
{
	char val;
	Node *next;
public:
	Node();
	friend class ListADT;
};

class ListADT
{
	Node *head;
public:
	ListADT();
	void insert(char);
	void insertAtEnd(char);
	void insertInMiddle(char);
	char remove();
	void removeInMiddle();
	char removeAtEnd();
	char peep1();
	int numberOfNodes();
	bool isempty();
	virtual ~ListADT();
};

#endif /* LISTADT_H_ */
