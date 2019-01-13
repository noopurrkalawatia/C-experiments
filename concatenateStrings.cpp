#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

string concatenateString(string input1, int value)
{
    string result = "";
    for(int i = 0 ; i < value ; ++i)
    {
        result = result + input1;
    }
    cout << result << endl;
    return result;
}


int main() 
{
    string result;
    string input1 = "utta";
    int value = 3 ;
    result = concatenateString(input1,value);
}
