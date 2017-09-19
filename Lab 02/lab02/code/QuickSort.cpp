
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void MyFunc ( int *array, int size ) {  
  
  int pivot = array[size-1];

  for (int i = 0; i < size -1; i ++) {
    for (int j = 0; j < size -1; j++) {
      if (array[i] <= pivot) {
        swap(array[i],array[j]);
      }
    }
  }

  swap(x, array[size-1]);
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
  MyFunc(Sequence, int arraySize); 
    
  // Output the result
  for(int i=0; i<arraySize; i++)
      cout << Sequence[i] << endl;
    
  // Free allocated space
  delete[] Sequence;
}
