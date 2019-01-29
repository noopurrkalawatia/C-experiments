#include <iostream>
using namespace std;

#include <stdio.h>

int main() 
{
	int noOfTestcases = 0;
	cin >> noOfTestcases;
	
	while(noOfTestcases--)
	{
	    int size;
	    cin >> size;
	    int array[size];
	    for(int i = 0 ; i < size; ++i)
	    {
	        cin >> array[i];
	    }
	    
	    int query; 
	    cin >> query;
	    
	    for(int i = 0 ; i < size; ++i)
	    {
	       cout <<  array[(i+query)%size] << " " ;
	    }
	    
	    cout << endl ;
	    
	}
	return 0;
}
