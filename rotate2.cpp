#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include <stdio.h>

int main() 
{
    int noOfTestcases = 0;
    cin >> noOfTestcases;
    
    for(int i = 0 ; i < noOfTestcases; ++i)
    {
        int ipPara[2];
        
        for(int i = 0 ; i < 2; ++i)
        {
            cin >> ipPara[i];
        }
        
        int size = ipPara[0];
        int query = ipPara[1];
        int array[size];
        
        for(int i = 0; i < size; i++)
        {
            cin >> array[i];
        }
        
        
        for(int i = 0 ; i < size; ++i)
	      {
            cout <<  array[(i+query)%size] << " " ;
	      }
        cout << "\n";
        
    }
	return 0;
}
