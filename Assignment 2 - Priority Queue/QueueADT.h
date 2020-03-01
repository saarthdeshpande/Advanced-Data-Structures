/*
 * QueueADT.h
 *
 *  Created on: 26-Feb-2020
 *      Author: mock
 */

#ifndef QUEUEADT_H_
#define QUEUEADT_H_

#include<iostream>
using namespace std;

struct Patient
{
	string name;
	int age;
	char sex;
	string patientID;
};

struct Node
{
	Patient data;
	int priority;
	Node *next;
};

class QueueADT {
	Node *front, *rear;
public:
	QueueADT();
	Node* getNode(Patient,int);
	void enqueue(Patient,int);
	void display();
	void dequeue();
	bool isempty();
	Patient peek();
	virtual ~QueueADT();
};

#endif /* QUEUEADT_H_ */
