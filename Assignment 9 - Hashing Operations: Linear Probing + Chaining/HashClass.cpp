/*
 * HashClass.cpp
 *
 *  Created on: 25-Mar-2020
 *      Author: saarth
 */

#include "HashClass.h"

HashClass::HashClass() {
	// TODO Auto-generated constructor stub
	H = NULL;
	replacementPresent = size = 0;
}

HashClass::~HashClass() {
	// TODO Auto-generated destructor stub
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
	int resp;
	delete []H;		// delete existing table if any
	cout <<"\nEnter Size of Hash Table: ";
	cin >> size;
	H = new hashTable[size];
	for(int i = 0;i < size;i++)		// initialize values of hash table
		H[i].flag = 0, H[i].chain = -1, H[i].name = H[i].mobileNumber = "-1";
	do
	{
		cout << "\nType of Implementation:\n1. Chaining WITH Replacement\n2. Chaining WITHOUT Replacement\nYour Choice: ";
		cin >> resp;
	}while(resp != 1 && resp != 2);
	if(resp == 1)
		replacementPresent = true;
	else
		replacementPresent = false;
}

void HashClass::insertWithReplacement(hashTable x)
{
	int index = hashFunction(x.mobileNumber);	// expected index for placing given key
	cout << "\nExpected Index = " << index << endl;
	if(H[index].flag == 0)	// if there is no entry at generated index
	{
		H[index] = x;	// entry is put at generated index itself, without probing
		H[index].flag = 1;	// flag is set to 1, i.e., an element is present here
	}
	else if(hashFunction(H[index].mobileNumber) == index)	// if hashcode of pre-existing entry at generated index is same as index (i.e. not probed)
	{
			int count = 0, j = index;
			while(H[j].flag == 1 && count < size)	// linear probing => j will be empty location where insertion is possible
			{
				j = (j + 1) % size;
				count++;
			}
			if(count == size)
			{
				cout << "\nHash Table Full.\n";
				return;
			}
			if(hashFunction(H[index].mobileNumber) != index)	// if element present at generated index has been probed, i.e., its expected index is not its actual index
			{
				j = hashFunction(H[index].mobileNumber);	// actual index of pre-existing element at generated index
				while(H[j].chain != index)		// traverse the chain for appropriate insertion
					j = H[j].chain;
				H[j].chain = H[index].chain;

				while(H[j].chain != -1)
					j = H[j].chain;
				H[j].chain = index;

				H[j] = H[index];
				H[j].flag = 1;
				H[j].chain = -1;

				H[index] = x;
				H[index].flag = 1;
				H[index].chain = -1;
			}
			else	// if element present at generated index has NOT been probed, i.e., its expected index IS its actual index
			{
				H[j] = x;	// insert new entry at j-th location
				H[j].flag = 1;
				H[j].chain = -1;

				count = index;
				while(H[count].chain != -1)		// traverse the chain so as to update second last value of chain
					count = H[count].chain;
				H[count].chain = j;		// update value of second last value of chain from -1 to j
			}
	}
	else	// replacement, i.e., insert at generated index && change location of pre-existing element, also updating its chain
	{
		int count = 0, j = index;
		while(H[j].flag == 1 && count < size)	// linear probing => j will be empty location where insertion is possible
		{
			j = (j + 1) % size;
			count++;
		}
		if(count == size)
		{
			cout << "\nHash Table Full.\n";
			return;
		}
		int i = hashFunction(H[index].mobileNumber);	// expected hashcode of entry present at generated index
		while(H[i].chain != index)	// traverse the chain if present
			i = H[i].chain;
		H[i].chain = H[index].chain;
		while(H[i].chain != -1)
			i = H[i].chain;
		H[j] = H[index];
		H[j].flag = 1;	// j will be new location of pre-existing entry
		H[j].chain = -1;
		H[i].chain = j;	// i will be second last location of chain

		H[index] = x;	// insert new entry
		H[index].chain = -1;
	}
}

void HashClass::insertWithoutReplacement(hashTable x)
{
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

void HashClass::insert() // function decides use insertion with / without chaining based on response taken during creation of table
{
	hashTable temp;
	cout << "\nNew Entry:\n\nName: ";
	scanf("\n");
	getline(cin,temp.name);
	cout <<"Mobile Number: ";
	getline(cin,temp.mobileNumber);
	temp.chain = -1;
	temp.flag = 1;
	if(replacementPresent)
		insertWithReplacement(temp);
	else
		insertWithoutReplacement(temp);
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

bool HashClass::replacement()	// returns whether replacement present (useful for better user interface)
{
	return replacementPresent;
}
