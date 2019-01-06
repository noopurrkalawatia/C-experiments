#include <iostream>
using namespace std;
#include <string>

int testNumber(string input)
{
    int size = input.size();
    int countZero = 0;
    for(int i = 0; i < size; ++i)
    {
        if('0' == input[i])
        {
            ++countZero;
        }
    }
    return countZero;
}

int main() 
{
	int noOfTestCases = 0,zeroes = 0;
	string input;
	char firstChar = input[0];
    cin >> noOfTestCases;
	for(int i = 0 ; i < noOfTestCases; ++i)
	{
	    cin >> input;
	    char firstChar = input[0];
	    zeroes = testNumber(input);
	    if(zeroes > 0 && firstChar != '0')
	    {
	        cout << "YES" << endl;
	    }
	    else
	    {
	        cout << "NO" <<endl;
	    }
	}
	return 0;
}
