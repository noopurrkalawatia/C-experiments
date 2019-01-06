#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int checkString(string input)
{
    int len = input.size();
    for(int i = 0; i < len; ++i)
    {
        if(isdigit(input[i]) == false)
        {
            return false;
        }
    }
    return true;
}

int main(void) 
{
    string input;
    int result;
    int noOfTestCases = 0; 
    cin >> noOfTestCases;
    for(int i = 0 ; i < noOfTestCases; ++i)
    {
        cin >> input;
        result = checkString(input);
        if(result)
        {
            cout << "Is an integer" << endl; 
        }
        else
        {
            cout << "Is a string" << endl;
        }
    }  
    return 0;
}
