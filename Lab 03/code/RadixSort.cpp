#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct T{
	int K[10];
};

void myFunc(T* array, int size, int position)
{
	T* result;
	result = new T[size];
	int count[10];
	for(int i = 0; i<10; i++) {
		count[i]= 0;
	}

	for(int j = 0; j<size;j++) {
		count[array[j].K[position]]++;
	}

	for(int x = 1; x<10; x++) {
		count[x] = count[x]+count[x-1];
	}

	for(int y = size-1; y >=0; y--)
	{
		result[count[array[y].K[position]]-1] = array[y];
		count[array[y].K[position]]--;
	}

	for(int i = 0; i<size; i++) {
		array[i] = result[i];
	}
	delete result;
}

void radixSort (T* array, int size) {  
	for(int i = 9; i >=0; i--)
	{
		myFunc(array, size, i);
	}
}

int main(int argc,char **argv) {
  int arraySize;

  // Get the size of the sequence
  cin >> arraySize;

  T* array;
  array = new T [arraySize];
    
  // Read in the sequence
  for(int i = 0; i<arraySize; i++)
  {
	for(int j = 0; j<10; j++)
	{
		cin>>array[i].K[j];

	}
  }
  
  radixSort(array, arraySize); 
    
  // Output 
  for(int i=0; i<arraySize; i++)
      {
	for(int j = 0; j<10;j++)
		cout<<array[i].K[j]<<";";
	cout<<endl;
      }
    
  // Free allocated space
  delete[] array;
}

