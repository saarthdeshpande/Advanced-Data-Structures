//============================================================================
// Name        : ass4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "TreeADT.h"

int main()
{
	TreeADT t;
	char *inputExpression = new char[100];
	int resp;
	do
	{
		cout << "\nExpression Tree\n\n1. Input Expression\n2. Display Traversals\n3. Exit\nYour Choice: ";
		cin >> resp;
		switch(resp)
		{
			case 1: cout << "Input PostFix / PreFix Expression: ";
					cin.ignore();
					cin >> inputExpression;
					t.createTree(inputExpression);
					break;
			case 2: cout << "\nRECURSIVE\n";
					cout << "\nPreOrder: "; t.RecursivePreOrder(t.getRootNode());
					cout << "\nInOrder: "; t.RecursiveInOrder(t.getRootNode());
					cout << "\nPostOrder: "; t.RecursivePostOrder(t.getRootNode());
					cout << "\n\nNON - RECURSIVE\n";
					cout << "\nPreOrder: "; t.NonRecursivePreOrder(t.getRootNode());
					cout << "\nInOrder: "; t.NonRecursiveInOrder(t.getRootNode());
					cout << "\nPostOrder: "; t.NonRecursivePostOrder(t.getRootNode());
					break;
			case 3: return 1;
			default: cout << "Please enter a valid response!\n";
		}
	}while(resp != 3);
	return 0;
}
