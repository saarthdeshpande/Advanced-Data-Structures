/*
 * QueueADT.cpp
 *
 *  Created on: 26-Feb-2020
 *      Author: mock
 */

#include "QueueADT.h"

#include<iostream>
using namespace std;

QueueADT::QueueADT() {
	// TODO Auto-generated constructor stub
	front = NULL;
	rear = NULL;
}

QueueADT::~QueueADT() {
	// TODO Auto-generated destructor stub
}

Node* QueueADT::getNode(Patient p,int priority)	// function to return a new node for queue
{
	Node* n = new Node;	// allocate memory for new node in queue
	n -> data = p;
	n -> next = NULL;
	n -> priority = priority;
	return n;
}

void QueueADT::display()
{
	Node *temp = rear;
	while(temp != NULL)	// traverse through queue in descending order of priority (highest priority = 1; lowest = 3)
	{
		cout << endl;
		cout << "PatientID: " << (temp -> data).patientID << endl;
		cout << "Name: " << (temp -> data).name << endl;
		cout << "Sex: " << (temp -> data).sex << endl;
		cout << "Age: " << (temp -> data).age << endl;
		temp = temp -> next;
	}
}

bool QueueADT::isempty()	// function returns true if queue is empty, else returns false
{
	if(rear == NULL)
		return 1;
	return 0;
}

void QueueADT::enqueue(Patient p,int priority)
{
	Node *temp = getNode(p,priority);
	if(isempty())	// if queue is empty
	{
		front = rear = temp;
		return;
	}
	if(rear -> priority > temp -> priority)	// if new node has higher priority than highest priority node in queue
	{
		temp -> next = rear;
		rear = temp;	// new node is now 'rear' node
		return;
	}
	Node *temp2 = rear;
	while((temp -> priority > temp2 -> priority)&&(temp2 != NULL))		// traverse through queue to insert at appropriate position
	{
		if(temp2 -> next == NULL)	// if reached last element, break out of loop so as to insert new node at last position and make it the last node
			break;
		temp2 = temp2 -> next;
	}
	Node* temp3 = temp2 -> next;
	temp2 -> next = temp;
	temp -> next = temp3;
}

void QueueADT::dequeue()
{
	Node *temp = rear;	// node to be deleted is stored in temporary variable
	rear = rear -> next;	// 'rear' pointer points to next address, as it has to be deleted
	delete temp;
}

Patient QueueADT::peek()	// returns record from highest priority node
{
	return rear -> data;
}
