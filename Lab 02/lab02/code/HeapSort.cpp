
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void MaxHeap(int *array, int size) {
// (size-2)/2 gives the last internal node

  for (int i = 0; i < size/2; i++) {

    if (array[i] < array[(2*i) + 1]) {
      int temp = array[i];
      array[i] = array[(2*i)+1];
      array[(2*i)+1] = temp;
      MaxHeap(array,size);

    } else if (array[i] < array[i*2 + 2]) {
      int temp = array[i];
      array[i] = array[(2*i)+2];
      array[(2*i)+2] = temp;
      MaxHeap(array,size);
    }
  }  
}

void MyFunc ( int *array, int size ) {  
  
  int k = size;

    // MaxHeap(array,size);
  for (int i = 0; i < size; i++) {
    MaxHeap(array,k-1);
    int temp = array[0];
    array[0]=array[k-1];
    array[k-1]=temp;
    k--;
  }
}


int main(int argc,char **argv) {

  int *Sequence;
  int arraySize;

  // Get the size of the sequence
  cout <<"Enter size\n";
  cin >> arraySize;

  // Allocate enough memory to store "arraySize" integers
  Sequence = new int[arraySize];
    
  // Read in the sequence
  cout << "Enter the sequence\n";
  for ( int i=0; i<arraySize; i++ )
    cin >> Sequence[i];

  // Run your algorithms to manipulate the elements in Sequence
  MyFunc(Sequence, arraySize); 
    
  // Output the result
  cout << "The sequence is:\n";
  for(int i=0; i<arraySize; i++)
      cout << Sequence[i] << endl;

    
  // Free allocated space
  delete[] Sequence;
}
