
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;


 void MyFunc(T *array, int place, int size) {  
    int pHolder[10];
    T* end;
    end = new T[size];
    

    for (int i = 0; i < 10; i++) {
      end[i] = 0;
    }

    for (int j = 0; i < size; j++) {
      end[array[i].key[place]];
    }

    for(int x = 0; x < 10; x++) {
      end[x] = end[x] + end[x-1];
    }

    for (int y = size -1; y > 0; y--) {
      result[end[array[i].key[place]]-1] = array[i];
      end[array[i].key[place]]--;
    }
}

// Radix sorts out index by index 
// We only need to compare 10 spots so from 0 - 9
void radixS(T* array, int arraySize) {
  for (int i = 0; i < 10; i++) {
    // Send an array, size, and place
    MyFunc(array,i,arraySize);
  }
}

struct T {
  int K[10];
};

int main(int argc,char **argv) {

  int arraySize;
  int value;

  T* array;
  array = new T [arraySize];

  //Making a two dimensional ghetto array to store vector values
  for (int x = 0; x < arraSize; x++) {
    // Size of 10 because there's only 0-9 placesible values
    for (int y = 0; y < 10; y++) {
      cin >> array[x].K[j];
    }
  }

  radixS(array,arraySize);

  //Output
  for (int x = 0; x <arraySize; x++) {
    //Range is from 0 to 10 again cause values range from 0-9
    for (int y = 0; y < 10; y++) {
      cout << array[x].key[y] << "\n";
    }
  }
   delete[] Sequence;
  }
 
