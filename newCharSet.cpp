#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

void changeNew(string input, string charSet)
{
    unordered_map<char,char>charSetMap;
    int i = 0 , size = charSet.size();
    string result;
    for(char j = 'a' ; j <= 'z' , i < size; ++j , ++i)
    {
        charSetMap.insert(std::make_pair(charSet[i],j));
    }
    
    unordered_map<char,char>::const_iterator got;
    for(int i = 0 ; i < input.size(); ++i)
    {
        got = charSetMap.find(input[i]);
        if(got != charSetMap.end())
        {
            result = result + got->second;
        }
    }
    
    cout << "Result is : " << result << endl;
}


int main() 
{
    string input = "utta";
    string charSet; 
    charSet = "qwertyuiopasdfghjklzxcvbnm";
    changeNew(input,charSet);
}
