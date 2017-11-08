#include <iostream>
#include <limits.h>
#include <vector> 
using namespace std;

// Placed parenthesis around the respective A#
// i will start at 1
void PrintParenthesis(vector< vector<int> > &p, int i, int j) {
	if(i == j) 
	{
		cout << "A" << (i-1);
	} else {
		cout << "(";
		PrintParenthesis(p,i,p[i][j]);
		PrintParenthesis(p,p[i][j]+1,j);
		cout << ")";
	}
}

// Build from top down
int main ()
{
	int size, i,j,k,l,value,lowestCost;
	scanf("%d", &size); //n is n
	int oArray[size+1]; // Original Array 
	int costTable[size + 1][size + 1];
	vector <vector<int> > pArray; 
	pArray.resize(size+1, vector<int>(size+1,0));

	for (int i = 0; i <= size; i++)
	{
		scanf("%d", &oArray[i]);
	}

	for (int i = 1 ; i <= size; i++) // Work done for a single matrix is 0
	{
		costTable[i][i] = 0;
	}

	//Psudo
	for (l = 2; l <= size; l++) {
		for (i = 1; i <= size - l + 1; i ++) {
			j = i + l - 1;
			costTable[i][j] = INT_MAX; // Sets all the values to max possible value
			for (k = i; k <= j - 1; k++) {
				lowestCost = costTable[i][k] + costTable[k+1][j] + oArray[i-1] * oArray[k] * oArray[j];
				if (lowestCost < costTable[i][j]) // if vactor multiplication takes less actions than previous, replace
				{
					costTable[i][j] = lowestCost;
					pArray[i][j] = k; // Saves a copy 
				}
			}
		}
	}
	// return costTable[1][s]
	cout << costTable[1][size] << "\n"; // Gives the lowest cost to multiply the matrix
	PrintParenthesis(pArray,1,size);
	cout << "\n";
	
	return 0;
}