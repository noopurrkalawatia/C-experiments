#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void calculatePanagram(string input, int value)
{
    vector<bool> mark(26,false);
    int index = 0;
	for(int i=0 ; i < input.size() ; ++i)
	{
	    if(input[i] >= 'A' && input[i] <= 'Z')
	    {
	        index = input[i] - 'A';
	    }
	    
	    if(input[i] >= 'a' && input[i] <= 'z')
	    {
	        index = input[i] - 'a';
	    }
	    mark[index] = true; 
	}
	
	int output = 0 ;
	for(int j = 0; j < mark.size(); ++j)
	{
	    if(mark[j] == false)
	    {
	        ++output;
	    }
	}
	

	if(output <= value)
	{
	    cout << 1 << endl;
	}
	else
	{
	    cout << 0 << endl;
	}
}

int main() 
{
    string input;
    int noOfTestcases = 0 ;
    cin >> noOfTestcases;
    int query;
    string str;
    int result = 0;
    
    
    for (int i = 0 ; i < noOfTestcases ; ++i)
    {
        cin.ignore();
        getline(cin,str);
        cin >> query;
        if(str.size() >= 26)
        {
           calculatePanagram(str, query);
        }
        else
        {
            result = 0;
            cout << result << endl;
        }
    }

	
	return 0;
}
