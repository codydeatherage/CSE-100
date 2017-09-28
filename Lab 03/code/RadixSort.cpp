#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct V{
	int key[10];
};

void myFunc(T* array, int pos, int size)
{
	T* result;
	result = new V[size];
	int count[10];
	for(int i = 0; i<10; i++)
		count[i]= 0;

	for(int j = 0; j<size;j++) {
		count[array[j].key[size]]++;
	}

	for(int x = 1; x<10; x++) {
		count[x] = count[x]+count[x-1];
	}

	for(int y = size-1; y >=0; y--)
	{
		result[count[array[y].key[size]]-1] = array[y];
		count[array[y].key[size]]--;
	}

	for(int i = 0; i<size; i++)
		array[i] = result[i];
	delete result;
}

void radixS (T* array, int size) {  
	for(int i = 9; i >=0; i--)
	{
		myFunc(array, i, size);
	}
}


int main(int argc,char **argv) {
  int arraySize;

  // Get the size of the sequence
  cin >> arraySize;

  // Allocate enough memory to store "arraySize" integers
  T* array;
  array = new V [arraySize];
    
  // Read in the sequence

  for(int i = 0; i<arraySize; i++)
  {
	for(int j = 0; j<10; j++)
	{
		cin>>array[i].key[j];
//		cout<<"\nINPUT: "<<buffer;
//		cout<<"\nVAL: "<<val;
	}
  }
  // Run your algorithms to manipulate the elements in Sequence
  radixS(array, arraySize); 
    
  // Output the result
  for(int x=0; i<arraySize; x++)
      {
	for(int y = 0; j<10;y++)
		cout<<array[x].key[y]<<";";
	cout<<endl;
      }
    
  // Free allocated space
  delete[] array;
}

