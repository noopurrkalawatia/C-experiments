#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string extractNumbers(string input)
{
    int size = input.size(),counter = 0,flag = 0;
    string result = "";
    
    if(size == 0)
    {
        return input;
    }
    
    string temp = input;
    
    for (int i = 0; i < size; ++i)
        {
            char ch = tolower(temp[i]);
            if(ch >= '0' && ch <= '9')
            {
                result = result + ch;
                counter++;
                flag = 1;
            }
            else if(result.size() > 0 && result[counter - 1] != ' ')
            {
                result+=" ";
	        counter++;
            }
        }
    
    if(!flag)
    {
        return "No Integers";
    }
    
    return result;
}

int main() 
{
    int noOfTestcases = 0;
    cin >> noOfTestcases;
    string input, result;
    cin.ignore();
    for(int i = 0; i < noOfTestcases; ++i)
    {
        getline(cin,input);
        result = extractNumbers(input);
        cout << result << endl;
    }
	return 0;
}
