#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Hash.h"
#define iter list<int>::const_iterator

using namespace std;

/****************************************************************
 * CONSTRUCTOR
 ****************************************************************/
Hash::Hash(int bNo) {
	//Resizes the container so that it contains  bNo elements
	table.resize(bNo);
}

/****************************************************************
 * DESTRUCTOR
 ****************************************************************/
Hash::~Hash() {
  // Write code to remove and deallocate everything
}

void Hash::Insert(int toInsert) {
	// Stays in range of the list; toInsert% bNo
	// push_front pushes the value into the box; chaining
  table[toInsert % bNo].push_front(toInsert);
}

bool Hash::Delete(int toDelete) {
	// Need to call search function to find the value being deleted
	// If true, delete the value, else return false;
	int _bucket;
	int _pos;

	if (Search(toDelete, _bucket, _pos)) {
		// advance (iterator, n)
		// iteration to be advanced with the value of n
		iter I = table[_bucket].begin();
		advance(I,_pos);
		table[_bucket].erase(I);

	} 
		return false;
}

bool Hash::Search(int key, int& _bucket, int& _pos) {

 	// For loops checks the "key's" index and sets I as the beginning of it;
 	// Makes sure I doesn't equal the end of the list or NULL
 	// Incrementing the list goes down the indexes and checks the value;
 	int i = 0;
 	for (iter I = table[key %  bNo].begin(); I != table[key %  bNo].end(); I++) {
		if (*I == key) {
			// returns back the key's bucket;
			// _pos is the index within the bucket;
			_bucket = key %  bNo;
			_pos = i;
			return true;
		}
		i++;
 	}
	return false;
}

void Hash::Print() {

	// bNo is just the size of the table
	// If the table hasn't reached the end yet, point to the next one
	// If it does reach the end, print an arrow and back out the bucket.
  for (int i = 0; i <  bNo; i++) 
  	{
  	cout << i << " : ";
  	iter I = table[i].begin();
  	//Checks to make sure I isn't equal to NULL
  		for ( ;  I != table[i].end(); ++I) {
  			cout << *I;
  			if (++I != table[i].end()) {
  				cout << "->";
  			}
  			I --;
  		}
  		cout << endl;
	}
}

