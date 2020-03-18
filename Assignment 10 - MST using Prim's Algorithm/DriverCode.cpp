//============================================================================
// Name        : Assignment 10 - MST using Prim's Algorithm
// Author      : Saarth Deshpande 23150
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Graph.h"

int main() {
	Graph g;
	int resp;
	do
	{
		cout << "\nPrim's Algorithm\n\n1. Create Graph\n2. Exit\nYour Choice: ";
		cin >> resp;
		switch(resp)
		{
			case 1: g.createGraph();
					break;
			case 2: return 1;
			default: cout << "\nPlease enter a valid response.\n";
		}
	}while(resp != 1 && resp != 2);
	do
	{
		cout << "\n1. Create Graph\n2. Display Graph\n3. Display MST\n4. Exit\nYour Choice: ";
		cin >> resp;
		switch(resp)
		{
			case 1: g.createGraph();
					break;
			case 2: g.display();
					break;
			case 3: g.PrimsAlgorithm();
					break;
			case 4: return 1;
			default: cout << "\nPlease enter a valid response.\n";
		}
	}while(resp != 4);
	return 0;
}
