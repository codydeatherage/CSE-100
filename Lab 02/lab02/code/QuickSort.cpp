
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void MyFunc ( int *array, int start, int max ) {  

  int pivot = array[max];
  int j = start-1;

if (start < max) {
  for (int i = start; i <= max; i++) {
    if(array[i] < pivot) {
      j++;
      swap(array[j],array[i]);
    }
  }
  if(array[j+1] > array[max]) {
    swap (array[j+1], array[max]);
  }
  MyFunc(array, start, j);
  MyFunc(array, j+2 , max);
  }

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
  MyFunc(Sequence, 0, arraySize-1); 
    
  // Output the result
  for(int i=0; i<arraySize; i++)
      cout << Sequence[i] << endl;
    
  // Free allocated space
  delete[] Sequence;
}
