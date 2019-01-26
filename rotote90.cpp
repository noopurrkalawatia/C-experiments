#include <iostream>
#include <stdio.h>
using namespace std;
#include <algorithm>

int main() 
{
    int noOfTestCases = 0,noOfRows,temp1,temp2,noOfCols;
    cin >> noOfTestCases;
    
    for(int i = 0 ; i < noOfTestCases; ++i)
    {
        cin >> noOfRows;
        int matrix[noOfRows][noOfRows];
        for(int i = 0 ; i < noOfRows; ++i)
        {
            for(int j = 0; j < noOfRows; ++j)
            {
                cin >> matrix[i][j];
            }
        }
        
        for (int i = 0; i <= noOfRows - 1; i++)
        { 
            for (int j = noOfRows - 1; j >= 0; --j) 
            { 
                cout << matrix[j][i] << " "; 
            } 
        } 
        
        cout << endl;
        
    }
	//code
	return 0;
}
