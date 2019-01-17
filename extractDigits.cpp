#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string extractNumbers(string input)
{
    int size = input.size();
    string result = "";
    
    if(size == 0)
    {
        return input;
    }
    
    stringstream ss;
    string temp;
    ss << input;
    
    while(!ss.eof())
    {
        ss >> temp;
        int size = temp.size();
        
        for (int i = 0; i < size; ++i)
        {
            char ch = tolower(temp[i]);
            if(ch >= '0' && ch <= '9')
            {
                result = result + ch;
            }
        }
        result = result + " ";
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
