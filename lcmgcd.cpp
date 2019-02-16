#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int calcGCD(vector<int> numbers);

void calculateLCMGCD(vector<int> numbers)
{
    vector<int> result(2);
    sort(numbers.begin(),numbers.end());
    result[1] = calcGCD(numbers);
    result[0] = (int)((numbers[0] * numbers[1]) / result[1]);
    
    cout << result[0] << " " << result[1] << endl;
    return result;
}

int calcGCD(vector<int> numbers)
{
    int a = numbers[0];
    int b = numbers[1];
    int x = 1;
    while(x != 0)
    {
        x = b % a;
        if(x == 0)
        {
            return a;
        }
        b = a;
        a = x;
    }
}

int main() 
{
	int noOfTestcases = 0, j = 0;
	
	cin >> noOfTestcases;
	string input;
	cin.ignore();
	for(int i = 0;i < noOfTestcases;++i)
	{
	    j = 0;
	    getline(cin,input);
	    
	    vector<int> temp(2);
	    stringstream ss;
	    ss << input;
	    while(!ss.eof())
	    {
	        ss >> temp[j];
	        j++;
	    }

      calculateLCMGCD(temp);
	}
	return 0;
}
