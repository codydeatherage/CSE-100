
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void MyFunc ( int *array, int size ) {  
    
    int max = maxValue(array, size);
    int tempArray[size];
    int sortedArray[size];
    int bucket[10] = {0}; // Possible index values 0-9 {0,0,0,0,0,0,0,0,0,0}
    int index = 1;

    // Checks to see if index goes out of bounds
   if (max/index > 0) {
      for (int i = 0; i < size; i ++) {
        //Increments a bucket's 0-9 index so count a number's last index is accounted
        bucket[(array[i]/index) % 10]++;
      }
      // Store the values within the bucket into a tempArray
      for (int i = 0; i < size; i++) {
        
      }

   }  
}

int maxValue(int *array, int size) {

  int max = 0;
  // If it's an array size of 1, it's the max
  max = array[0];
  for (int i = 0; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
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
  MyFunc(Sequence, arraySize); 
    
  // Output the result
  for(int i=0; i<arraySize; i++)
      cout << Sequence[i] << endl;
    
  // Free allocated space
  delete[] Sequence;
}
