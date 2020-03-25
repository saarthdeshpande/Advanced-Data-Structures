/*
 * HashClass.h
 *
 *  Created on: 25-Mar-2020
 *      Author: saarth
 */

#ifndef HASHCLASS_H_
#define HASHCLASS_H_

#include<iostream>
using namespace std;
#include<iomanip>

struct hashTable
{
	string name, mobileNumber;
	int chain;
	bool flag;
};

class HashClass
{
	int size;
	bool replacementPresent;
	hashTable *H;
public:
	HashClass();
	void createTable();
	int hashFunction(string);
	void insertWithoutReplacement(hashTable);
	void insertWithReplacement(hashTable);
	void insert();	// calls appropriate function based on whether replacement present or absent
	bool search(string);
	void removeElement(string);
	bool replacement();
	void display();
	virtual ~HashClass();
};

#endif /* HASHCLASS_H_ */
