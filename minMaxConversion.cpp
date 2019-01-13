#include <iostream>
#include <stdlib.h>
using namespace std;

int maxMinConversion(string input)
{
    int size = input.size();
    int value1 = atoi(input.c_str()) , sum = 0;
    for(int i = 0 ; i < size; ++i)
    {
        if('5' == input[i])
        {
            input[i] = '6';
        }
        else if('6' == input[i])
        {
            input[i] = '5'; 
        }
    }
    int value2 = atoi(input.c_str());
    sum = sum + value1 + value2;
    return sum;
}
int main() 
{
    int noOfTestcases = 0, result = 0;
    cin >> noOfTestcases;
    string input;
    for(int i = 0 ; i < noOfTestcases ; ++i)
    {
        cin >> input;
        result = maxMinConversion(input);
        cout << result << endl;
    }
	return 0;
}
