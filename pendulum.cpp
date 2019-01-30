#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void pendulum(int array[],int size)
{
    sort(array,array+size);
    
    int output[size];
    int mid = (size - 1) / 2,i,j;
    output[mid] = array[0];
    
    for(i = 1,j = 1; i <= mid; ++i)
    {
        output[mid+i] = array[j++];
        output[mid-i] = array[j++];
    }
    
    if (size % 2 == 0) 
    {
        output[mid+i] = array[j];
    }
    
    for(int i = 0 ; i < size; ++i)
    {
        cout << output[i] << " ";
    }
    cout << "\n";
}

int main() 
{
	int noOfTestcases = 0;
	cin >> noOfTestcases;
	
	for(int i = 0 ; i < noOfTestcases; ++i)
	{
	    int size;
	    cin >> size;
	    int array[size];
	    for(int i = 0; i < size; ++i)
	    {
	        cin >> array[i];
	    }
	    pendulum(array,size);
	}
	return 0;
}
