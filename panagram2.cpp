/*
Missing characters to make a string Pangram
Pangram is a sentence containing every letter in the English alphabet. 
Given a string, find all characters that are missing from the string, i.e., the characters that can make string a Pangram. 
We need to print output in alphabetic order.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void calculatePanagram(string input, int value)
{
    vector<bool> mark(26,false);
    int index = 0;
    for (int i = 0 ; i <= value ; ++i)
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
    
    int result;
    char eqChar;
    
    for(int j = 0; j < mark.size() ; ++j)
    {
        if(mark[j] == false)
        {
            result = j + 97;
            eqChar = static_cast<char>(result);
            cout << eqChar;
        }
    }
}
int main() 
{
    string input = "welcome to geeksforgeeks";
    calculatePanagram(input, input.size());
}
