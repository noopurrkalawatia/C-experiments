#include <iostream>
using namespace std;

#include <stdio.h>


bool deduce(string input1, string input2)
{
    int result = 0,count = 0;
    int equal = (input1.length() == input2.length()) ? 1 : 0;
    if(equal && (input1 != input2))
    {
        for(int i = 0; i < input1.length(); ++i)
        {
            if(input1[i] != input2[i])
            {
                count++;
            }
        }
        
        if(count <= 2)
        {
            return true;
        }
        
        return false;
    }
    
    else 
    {
        return false;
    }
    
}
int main() 
{
	int noOfTestcases = 0;
	string input1,input2;
	bool result = false;
	cin >> noOfTestcases;
	cin.ignore();
	for(int i = 0 ; i < noOfTestcases; ++i)
	{
	    getline(cin,input1);
	    getline(cin,input2);
	    result = deduce(input1,input2);
	    cout << result << endl;
	}
	return 0;
}
