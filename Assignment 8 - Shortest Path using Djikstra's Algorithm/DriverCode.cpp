//============================================================================
// Name        : Assignment 8 - Shortest Path using Djikstra's Algorithm
// Author      : Saarth Deshpande 23150
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Graph.h"

int main()
{
	int resp,src;
	Graph g;
	do
	{
		cout << "\nShortest Path via Djikstra's Algorithm\n\n1. Create Graph\n2. Exit\nYour Choice: ";
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
		cout << "\n1. Create New Graph\n2. Display Weighted Shortest Path\n3. Exit\nYour Choice: ";
		cin >> resp;
		switch(resp)
		{
			case 1: g.createGraph();
					break;
			case 2: cout << "\nSource Node: ";
					cin >> src;
					if(src < 0 || src >= g.returnVertices())
						cout << "\nInvalid Node.\n";
					else
						g.Djikstra(src);
					break;
			case 3: return 1;
			default: cout << "\nPlease enter a valid response.\n";
		}
	}while(resp != 3);
	return 0;
}
