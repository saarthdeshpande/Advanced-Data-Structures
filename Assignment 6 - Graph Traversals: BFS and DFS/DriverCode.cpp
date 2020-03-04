//============================================================================
// Name        : Assignment 6 - Graph Traversals: BFS and DFS
// Author      : Saarth Deshpande 23150
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Facebook.h"
#include <iomanip>

int main()
{
	Facebook f;
	int resp,month;
	do
	{
		cout << "SOCIAL NETWORK OPERATIONS\n\n1. Create Graph\n2. Exit\nYour Choice: ";
		cin >> resp;
		switch(resp)
		{
			case 1: f.createGraph();
					break;
			case 2:
					break;
			default: cout << "\nPlease enter a valid response.\n";
		}
	}while(resp != 1 && resp != 2);
	do
	{
		cout << "\n1. Create Graph\n2. Display Network\n3. Display Maximum Friends\n4. Display Maximum and Minimum Comments\n5. Birthday Month\n6. Exit\nYour Choice: ";
		cin >> resp;
		switch(resp)
		{
			case 1: f.createGraph();
					break;
			case 2: f.displayUsers();
					break;
			case 3: cout << "\nMaximum Friends: " << f.DFS(1) << endl;
					break;
			case 4: cout << "\nMaximum Comments: " << f.DFS(2) << endl;
					cout << "Minimum Comments: " << f.minCommentsBFS() << endl;
					break;
			case 5: cout << "\nEnter Birthday Month: ";
					cin >> month;
					cout << "Users with Birthday in Requested Month:\n";
					f.birthdayMonth(month);
					break;
			case 6: return 1;
			default: cout << "\nPlease enter a valid response.\n";
		}
	}while(resp != 6);
	return 0;
}
