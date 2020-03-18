//============================================================================
// Name        : Assignment 5 - Binary Search Tree Operations
// Author      : Saarth Deshpande 23150
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "TreeADT.h"

int main()
{
	TreeADT t,newTree;
	int nodeValue,resp;
	do
	{
		cout << "\nBINARY SEARCH TREE\n1. Insert Root Node\n2. Exit\nYour Choice: ";
		cin >> resp;
		switch(resp)
		{
			case 1: cout << "\nValue of Root Node: ";
					cin >> nodeValue;
					t.nonRecursiveInsertion(nodeValue);
					break;
			case 2: return 1;
			default: cout << "\nPlease enter a valid response.\n";
		}
	}while((resp != 1)&&(resp != 2));
	do
	{
		cout << "\n1. Insert Node\n2. Delete a Node\n3. Search a Node\n4. Create Mirror Image of Tree \n5. Display Tree\n6. Display Levelwise\n7. Exit\nYour Choice: ";
		cin >> resp;
		switch(resp)
		{
			case 1: cout << "\nValue of New Node: ";
					cin >> nodeValue;
					t.nonRecursiveInsertion(nodeValue);
					break;
			case 2: cout << "\nValue of Node to Delete: ";
					cin >> nodeValue;
					t.recursiveDelete(t.getRootNode(), nodeValue);
					break;
			case 3: cout << "\nValue to Search: ";
					cin >> nodeValue;
					if(t.recursiveSearch(t.getRootNode(),nodeValue))
						cout << "\nNode Exists!\n";
					else
						cout << "\nNode Unavailable.\n";
					break;
			case 4: t.nonRecursiveMirror();
					cout << "\nTree Mirroring Successful!\nChoose Display Format:";
					t.display(t.getRootNode());
					break;
			case 5: t.display(t.getRootNode());
					break;
			case 6: cout << "\nLevel-Order Traversal: "; t.printLevelOrder(t.getRootNode()); cout << endl;
					break;
			case 7: return 1;
			default: cout << "\nPlease enter a valid response.\n";
		}
	}while(resp != 7);
	return 0;
}
