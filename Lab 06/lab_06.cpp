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

//returns the least output when multiplying two or more matrices;
// call print within this function; Make sure space is correct
void MatrixChainOrder(int arr[], int size)
{
	int lowestCost,i,j,k,l;
	int costTable[size + 1][size + 1]; //We set size one bigger to start on the first index
	vector <vector<int> > pArray; 
	pArray.resize(size+1, vector<int>(size+1,0)); // resize the table to start on 1

	for (int i = 1 ; i <= size; i++) // Work done for a 
	{
		costTable[i][i] = 0;
	}

	//Psudo
	for (l = 2; l <= size; l++) {
		for (i = 1; i <= size - l + 1; i ++) {
			j = i + l - 1;
			costTable[i][j] = INT_MAX; // Sets all the values to max possible value
			for (k = i; k <= j - 1; k++) {
				lowestCost = costTable[i][k] + costTable[k+1][j] + arr[i-1] * arr[k] * arr[j];
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
	
}

// Build from top down
int main ()
{
	int n, value;
	scanf("%d", &n);
	int oArray[n+1];

	for (int i = 0; i <= n; i++)
	{
		scanf("%d", &oArray[i]);
	}
	MatrixChainOrder(oArray,n);
	return 0;
}