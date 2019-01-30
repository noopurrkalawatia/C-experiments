#include <iostream>
#include <vector>
#include<bits/stdc++.h> 
using namespace std;

int main() 
{
	int noOfTestcases = 0,i,j,index;
	
	cin >> noOfTestcases;
	for(i = 0 ; i < noOfTestcases; ++i)
	{
	    long long size = 0,count = 0, max = INT_MIN;
	    cin >> size;
	    int array[size];
	    int result[size];
	    
	    for(j = 0 ; j < size; ++j)
	    {
	        cin >> array[j];
	    }
	   
	    
	    for(j = size - 1 ; j >= 0; --j)
	    {
	        if(array[j] >= max)
	        {
	            max = array[j];
	            result[count] = array[j];
	            ++count;
	        }
	    }
	    
	    for(j = count - 1; j >= 0; --j)
	    {
	        cout << result[j] << " ";
	    }
	    cout << "\n";
	}
	return 0;
}
