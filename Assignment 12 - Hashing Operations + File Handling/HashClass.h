/*
 * HashClass.cpp
 *
 *  Created on: 01-Apr-2020
 *      Author: saarth
 */

#ifndef HASHCLASS_H_
#define HASHCLASS_H_

#include<iostream>
#include<fstream>
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
	hashTable *H;
public:
	HashClass();
	void createTable();
	int hashFunction(string);
	void writeToFile();
	void insertWithoutReplacement();
	bool search(string);
	void removeElement(string);
	void display();
	virtual ~HashClass();
};

#endif /* HASHCLASS_H_ */
