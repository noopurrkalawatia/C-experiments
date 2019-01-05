/*
Given a string, 
remove the punctuation from the string if the given character is a punctuation character as classified by the current C locale.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void checkPunctuation(string input)
{
    int len = input.size();
    for(int i = 0; i < len; ++i)
    {
        if(ispunct(input[i]))
        {
            input.erase(i--,1);
            --len;
        }
    }
    
    cout << "The output string is : " << input << endl;
}
int main() 
{
    string input = "%welcome' to @geeksforgeek<s";
    checkPunctuation(input);
}
