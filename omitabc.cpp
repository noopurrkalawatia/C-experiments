#include <iostream>
#include <string>
using namespace std;

string deduce(string input)
{
    string result = "",result2 = "";
    int i = 0, j = 0;
    while(i <= input.length() - 1)
    {
        if(input[i] == 'a' && input[i+1] == 'c')
        {
            i = i + 2;
        }
        else
        {
            result += input[i];
            ++i;
        }
    }
    
    for(int i = 0; i <= result.length() - 1; ++i)
    {
        if(result[i] == 'b')
        {
            continue;
        }
        else
        {
            result2 += result[i];
        }
    }
    return result2;
    
}

int main() 
{
    int noOfTestCases = 0;
    string input,result;
    cin >> noOfTestCases;
    cin.ignore();
    for(int i = 0; i < noOfTestCases; ++i)
    {
        getline(cin,input);
        result = deduce(input);
        cout << result << endl;
    }
	//code
	return 0;
}
