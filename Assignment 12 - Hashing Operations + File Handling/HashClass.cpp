/*
 * HashClass.cpp
 *
 *  Created on: 01-Apr-2020
 *      Author: saarth
 */

#include "HashClass.h"

HashClass::HashClass() {
	// TODO Auto-generated constructor stub
	H = NULL;
	size = 0;
	ifstream fp("Hashed Database.txt");
	if(fp.good())	// if database already exists
	{
		string name, contact;
		int chain, i = 0;
		fp >> name >> contact >> name;	// dummy headings (name, contact, chain)
		while(fp >> name >> contact >> chain)	// calculate size of hashtable
			size++;
		fp.clear();
		fp.seekg(0,ios::beg);	// go to beginning of file for copying data from database to hashtable in code segment
		fp >> name >> contact >> name;	// dummy headings (name, contact, chain)
		H = new hashTable[size];
		while(fp >> name >> contact >> chain)	// write every entry from file to hash table in code segment
		{
			H[i].name = name, H[i].mobileNumber = contact, H[i].chain = chain;
			if(name != "-1")
				H[i].flag = 1;
			i++;
		}
	}
	else
	{
		cout << "\nPre-existing database not found. Please create a table first and then access menu.\n\nCreation:\n";
		createTable();
	}
	fp.close();
}

HashClass::~HashClass() {
	// TODO Auto-generated destructor stub
}

void HashClass::writeToFile()
{
	ofstream fp;
	fp.open("Hashed Database.txt",ios::trunc);
	fp << "Name\tContact\tChain\n";
	for(int i = 0;i < size;i++)
		fp << H[i].name << "\t" << H[i].mobileNumber << "\t" << H[i].chain << endl;
	fp.close();
}

int HashClass::hashFunction(string key)		// hash function to generate unique index for given key
{
	int index = 0;
	for(int i = 0;key[i] != '\0';i++)
		index += (((i + 1) * key[i]) % size);
	index %= size;
	return index;
}

void HashClass::createTable()	// function to intialize the hash table entries
{
	delete []H;		// delete existing table if any
	cout <<"\nEnter Size of Hash Table: ";
	cin >> size;
	H = new hashTable[size];
	for(int i = 0;i < size;i++)		// initialize values of hash table
		H[i].flag = 0, H[i].chain = -1, H[i].name = H[i].mobileNumber = "-1";
	writeToFile();
}

void HashClass::insertWithoutReplacement()
{
	hashTable x;
	cout << "\nNew Entry:\n\nName: ";
	scanf("\n");
	getline(cin,x.name);
	cout <<"Mobile Number: ";
	getline(cin,x.mobileNumber);
	x.chain = -1;
	x.flag = 1;
	int index = hashFunction(x.mobileNumber);	// expected index for given key
	cout << "\nExpected Index = " << index << endl;
	if(H[index].flag == 0)	// if there is no entry at generated index
	{
		H[index] = x;
		H[index].flag = 1;
	}
	else
	{
			int count = 0, j = index;
			while(H[j].flag == 1 && count < size)	// linear probing => find nearest empty location for insertion
			{
				if(hashFunction(H[index].mobileNumber) == index)	// if entry present at generated index belongs there (0 probes), break from loop
					break;
				j = (j + 1) % size;
				count++;
			}
			if(count == size)
			{
				cout << "\nHash Table Full.\n";
				return;
			}
			while(H[j].chain != -1) // traverse till last element of chain (if present)
				j = H[j].chain;
			index = j;
			while(H[index].flag == 1 && count < size)	// find nearest empty location to insert -- linear probing
			{
				index = (index + 1) % size;
				count++;
			}
			if(count == size)
			{
				cout << "\nHash Table Full.\n";
				return;
			}
			H[index] = x;
			H[index].flag = true;
			if(j != index)
				H[j].chain = index;
	}
	writeToFile();
}

bool HashClass::search(string key)
{
	int count = hashFunction(key);	// expected index of given key
	while(H[count].mobileNumber != key && H[count].chain != -1)	// traverse chain if present to search for key
		count = H[count].chain;
	if(H[count].mobileNumber == key)
		return true;
	return false;
}

void HashClass::removeElement(string key)
{
	if(search(key))		// if entry exists
	{
		int expectedIndex = hashFunction(key), traversedIndex = expectedIndex;
		while(H[traversedIndex].mobileNumber != key && H[traversedIndex].chain != -1)	// traverse the chain if present
			traversedIndex = H[traversedIndex].chain;
		// traversedIndex holds actual location of element to be deleted
		// expectedIndex holds the hashcode generated index
		if(expectedIndex != traversedIndex)	// if chain was present
		{
			while(H[expectedIndex].chain != traversedIndex)	// traverse the chain for updating it
				expectedIndex = H[expectedIndex].chain;
			H[expectedIndex].chain = H[traversedIndex].chain;	// update chain
			H[traversedIndex] = {"-1","-1",-1,0};	// overwrite data
		}
		else	// if chain absent, simply overwrite data as '-1 -1 -1 0', 0 being the flag
			H[traversedIndex] = {"-1","-1",-1,0};
		writeToFile();
	}
	else
		cout << "\nRecord Does NOT Exist. Cannot be deleted.\n";
}

void HashClass::display()
{
	cout << "\nBucket Number\t\tName\t\tMobile Number\t\tChain\n";
	for(int i = 0;i < size;i++)
	{
		cout << setw(7) << i << setw(20) << H[i].name << setw(20) << H[i].mobileNumber << setw(20) << H[i].chain << endl;
	}
}
