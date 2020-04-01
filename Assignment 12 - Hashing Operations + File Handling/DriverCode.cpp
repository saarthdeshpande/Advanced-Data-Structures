//============================================================================
// Name        : Assignment 12 - Hashing Operations + File Handling
// Author      : Saarth Deshpande 23150
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "HashClass.h"
using namespace std;

int main() {
	HashClass t;
	string key;
	int resp;
	do
	{
		 cout << "\nLinear Probing - Without Replacement\n\n1. Create Table\n2. Insert Record\n3. Search Record\n4. Delete Record\n5. Display Table\n6. Exit\nYour Choice: ";
		cin >> resp;
		switch(resp)
		{
			case 1: t.createTable();
					break;
			case 2: t.insertWithoutReplacement();
					break;
			case 3: cout << "\nMobile Number to Search: ";
					cin.ignore();
					getline(cin, key);
					if(t.search(key))
						cout << "\nRecord Exists!\n";
					else
						cout << "\nRecord Does NOT Exist.\n";
					break;
			case 4: cout << "\nMobile Number to Search: ";
					cin.ignore();
					getline(cin, key);
					t.removeElement(key);
					break;
			case 5: t.display();
					break;
			case 6: return 1;
			default: cout <<"\nPlease enter a valid response.\n";
		}

	}while(resp != 6);
	return 0;
}
