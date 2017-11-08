#include <iostream>
#include <stdio.h>

using namespace std;

 void ActivitySort(int s[], int f[], int size) 
 {

	int i = 0;
	cout << i << " ";

	for (int j = 1; j < size; j++)
	{
		if (s[j] >= f[i]) 
		{
			cout << j << " ";
			i = j;
		}
	}

 }

int main()
{	
int s[] = {10, 12, 20};
int f[] = {20, 25, 30};
int size = sizeof(f)/sizeof(s[0]);

ActivitySort(s,f,size);
}