#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void formInitial(string input)
{
    int len = input.size();
    string result,init;
    result = toupper(input[0]); 
    for(int i = 0; i < len; ++i)
    {
        if(isspace(input[i]))
        {
            init = toupper(input[i + 1]);
            result = result + init;
        }
    }
    
    cout << result << endl;
}
int main() 
{
    string input = "noopur rajesh kumar kalawatia";
    formInitial(input);
}
