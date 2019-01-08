#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

char findExtra(string input1, string input2)
{
    unordered_map<char,int>inputMap;
    char result;
    
    string inputForMap = input1.size() > input2.size() ? input2 : input1;
    string other = input1.size() > input2.size() ? input1 : input2;
    int i = 0 , j = 0;
    for(i = 0; i < inputForMap.size(); ++i)
    {
        inputMap.insert(std::make_pair(inputForMap[i],i));
    }
    
    unordered_map<char,int>::const_iterator got;
    for(j = 0; j < other.size(); ++j)
    {
        got = inputMap.find(other[i]);
        if(got == inputMap.end())
        {
            result = other[i];
            return result;
        }
    }
}


int main() 
{
    char result;
    string input1 = "utta" , input2 = "uttas";
    result = findExtra(input1,input2);
    cout << "Extra character is :" << result << endl;
}
