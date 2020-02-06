//============================================================================
// Name        : Assignment 3 - Binary Tree Operations
// Author      : Saarth Deshpande 23150
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "TreeADT.h"

int main() {
	TreeADT t,newTree;
	int nodeValue,resp;
	do
	{
		cout << "\nBINARY TREE\n1. Insert Root Node\n2. Exit\nYour Choice: ";
		cin >> resp;
		switch(resp)
		{
			case 1: cout << "\nValue of Root Node: ";
					cin >> nodeValue;
					t.insertNode(nodeValue);
					break;
			case 2: return 1;
			default: cout << "\nPlease enter a valid response.\n";
		}
	}while((resp != 1)&&(resp != 2));
	do
	{
		cout << "\n1. Insert Node\n2. Display Tree\n3. Display Depth of Tree\n4. Display Leaf Nodes\n5. Create Copy of Tree\n6. Exit\nYour Choice: ";
		cin >> resp;
		switch(resp)
		{
			case 1: cout << "\nValue of New Node: ";
					cin >> nodeValue;
					t.insertNode(nodeValue);
					break;
			case 2: t.display(t.getRootNode());
					break;
			case 3: cout << "\nDepth of Tree = " << t.depth(t.getRootNode()) << endl;
					break;
			case 4: cout << "\nLeaf Nodes: ";
					t.displayLeafNodes(t.getRootNode());
					cout << endl;
					break;
			case 5: newTree.copy(t);
					cout << "\nCopy Successful!\nChoose Display Format:";
					newTree.display(newTree.getRootNode());
					break;
			case 6: return 1;
			default: cout << "\nPlease enter a valid response.\n";
		}
	}while(resp != 6);
	return 0;
}
