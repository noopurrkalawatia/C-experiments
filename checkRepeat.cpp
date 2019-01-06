#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int checkString(string input)
{
    int len = input.size();
    bool flag = false;
    for(int i = 0; i < len; ++i)
    {
        if(isdigit(input[i]) == false)
        {
            return false;
        }
    }
    
    return true;
}
int main() 
{
    string input;
    bool result;
    int noOfTestCases = 0; 
    for(int i = 0 ; i < noOfTestCases; ++i)
    {
        cin >> input;
        result = checkString(input);
        cout << "Result is : " << endl;
    }
    
}
