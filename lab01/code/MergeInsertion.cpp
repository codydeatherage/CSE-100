
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void MyFunc ( int *array, int size ) {  

  if (size < 100) {
  	for (int i = 1; i < size; i++) {
  		if (array[i] < array[i-1]) {
  			int temp = array[i];
  			array[i] = array[i-1];
  			array[i-1] = temp;
  			if (i > 1) 
  				i-=2;
  		}
	}
}

	if (size >= 100) {

    int *L, *R;
    L = (int*)malloc(sizeof(int)*(size/2));
    R = (int*)malloc(sizeof(int)*((size/2)+(size%2)));

    // Copies array to Left or Right according to bits and size
    memcpy(L,array,sizeof(int) * size/2);
    // Starts at the middle adds shit
    memcpy(R,array+(size/2),sizeof(int) * ((size/2) + (size%2)));

    MyFunc(L, size/2);
    MyFunc(R, size/2 + size%2);

    int i = 0; int j = 0;

    for (int x = 0; x < size; x++) {
       if (i == size/2) {
        array[x] = R[j];
        j++;
    
      } else if (j == size/2 + size%2) {
        array[x] = L[i];
        i++;
    
      }
        else if (L[i] >= R[j] ) {
        array[x] = R[j];
        j++;
        
      } else if (L[i] <= R[j]) {
        array[x] = L[i];
        i++;
       
      } 
    }
  }
}


int main(int argc,char **argv) {

  int *Sequence;
  int arraySize;

  // Get the size of the sequence
  // cout << "Enter array size:";
  cin >> arraySize;

  // Allocate enough memory to store "arraySize" integers
  Sequence = new int[arraySize];
    
  // Read in the sequence
  for ( int i=0; i<arraySize; i++ )
    cin >> Sequence[i];

  // Run your algorithms to manipulate the elements in Sequence
  MyFunc(Sequence, arraySize); 
    
  // Output the result
  // cout << "The ordered sequence of this is:\n";
  for(int i=0; i<arraySize; i++)
      cout << Sequence[i] << endl;
    
  // Free allocated space
  delete[] Sequence;
}
