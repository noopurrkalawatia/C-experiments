#include <iostream>
#include <math.h>
using namespace std;

void reverse(int array[],int size,int query)
{
    for (int i = 0; i < size; i += query) 
    { 
        int left = i; 
        int right = min(i + query - 1, size - 1); 
        while (left < right) 
            swap(array[left++], array[right--]); 
    } 
}

int main() 
{
	//code
	int noOfTestcases = 0;
	cin >> noOfTestcases;
	
	for(int i = 0 ; i < noOfTestcases; ++i)
	{
	    int inPara[2];
	    for(int i = 0 ; i < 2; ++i)
	    {
	        cin >> inPara[i];
	    }
	    int size = inPara[0];
	    int group = inPara[1];
	    int array[size];
	    
	    for(int i = 0; i < size; ++i)
	    {
	        cin >> array[i];
	    }
	    
	    reverse(array,size,group);
	    
	    for(int i = 0; i < size; ++i)
	    {
	        cout << array[i] << " ";
	    }
	    
	    cout << "\n";
	}
	return 0;
}
