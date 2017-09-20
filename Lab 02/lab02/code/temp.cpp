#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int split(int *array, int size, int i);

void QuickSort ( int *array , int size, int i) { //size isnt really a correct name here, size = high index 
	if(i<size)
	{
		int s = split(array,size,i);
		QuickSort(array,s-1,i);
		QuickSort(array,size,s+1);
	}
}

int split(int *array, int size, int i)
{
	int p = array[size];
	int m = i-1;
	for(int j = i; j<size;j++)
	{
		if(array[j]<p)
		{
			m++;
			swap(array[m],array[j]);
		}
	}
	if(array[size]<array[m+1])
		swap(array[m+1],array[size]);
	return m+1;
}


int main(int argc,char **argv) {

  int *Sequence;
  int arraySize;

  // Get the size of the sequence
  cin >> arraySize;

  // Allocate enough memory to store "arraySize" integers
  Sequence = new int[arraySize];
    
  // Read in the sequence
  for ( int i=0; i<arraySize; i++ )
    cin >> Sequence[i];

  // Run your algorithms to manipulate the elements in Sequence
  QuickSort(Sequence, arraySize-1,0); 
    
  // Output the result
  for(int i=0; i<arraySize; i++)
      cout << Sequence[i] << endl;
    
  // Free allocated space
  delete[] Sequence;
}