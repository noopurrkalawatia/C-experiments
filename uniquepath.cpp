#include <iostream>
using namespace std;

#include <stdio.h>

int uniquePath(int rows, int cols)
{
    int matrix[rows][cols];
    
    for(int i = 0; i < rows; ++i)
    {
        matrix[i][0] = 1;
    }
    
    for(int j = 0; j < cols; ++j)
    {
        matrix[0][j] = 1;
    }
    
    for(int i = 1; i < rows; ++i)
    {
        for(int j = 1; j < cols; ++j)
        {
            matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
        }
    }
    
    return matrix[rows - 1][cols - 1];
}

int main() 
{
    int noOfTestcases = 0,rows = 0,cols = 0,result = 0;
    cin >> noOfTestcases;
    
    for(int i = 0; i < noOfTestcases; ++i)
    {
        cin >> rows;
        cin >> cols;
        
        result = uniquePath(rows,cols);
        cout << result << endl;
    }
	//code
	return 0;
}
