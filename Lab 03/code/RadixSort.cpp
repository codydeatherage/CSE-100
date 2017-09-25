
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

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

void MyFunc ( int *array, int size ) {  
    

    int max = maxValue(array, size);
    int tempArray[size];
    int placeHolder[10] = {0}; // Possible index values 0-9 {0,0,0,0,0,0,0,0,0,0}
    int index = 1;
    int i = 0;

    // Checks to see if max number goes out index bounds
   if ((max/index) > 0) {
      for (i = 0; i < size; i ++) {
        //Increments a placeHolder's 0-9 index so a number's last index is accounted
        placeHolder[(array[i]/index) % 10]++;
      }
      //
      for (i = 1; i < 10; i++) {
        placeHolder[i] += placeHolder[i-1];
      }
      // Store the values within the placeHolder into a tempArray
      // In placeHolders, the lowest value is on the bottom of the placeHolder so we have to go max size to retrieve it
      // Store into array for now
     for (i = size - 1; i >= 0; i--) {
        tempArray[--placeHolder[(array[i]/index) % 10]] = array[i];
      }

      for (i = 0; i < size; i ++) {
        array[i] = tempArray[i];
      }
      index = index * 10; 
   }  
   
}

int main(int argc,char **argv) {

  int *Sequence;
  int arraySize;

  // Get the size of the sequence
  cout << "Enter array size:\n";
  cin >> arraySize;

  // Allocate enough memory to store "arraySize" integers
  Sequence = new int[arraySize];
    
  // Read in the sequence
  cout << "Enter values:\n";
  for ( int i=0; i<arraySize; i++ )
    cin >> Sequence[i];

  // Run your algorithms to manipulate the elements in Sequence

  MyFunc(Sequence, arraySize); 
    
  // Output the result
  cout << "The sorted sequence is:\n";
  for(int i=0; i<arraySize; i++)
      cout << Sequence[i] << endl;
    
  // Free allocated space
  delete[] Sequence;
}
