#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

bool checkPower(vector<int> numbers)
{
    int res1 = log(numbers[1]) / log(numbers[0]); 
    double res2 = log(numbers[1]) / log(numbers[0]);
    
    return(res1 == res2);
}

int main() 
{
	int noOfTestcases = 0, j = 0;
	cin >> noOfTestcases;
	
	cin.ignore();
	for(int i = 0; i < noOfTestcases; ++i)
	{
	    j = 0;
	    string input;
	    getline(cin,input);
	    
	    stringstream ss;
	    ss << input;
	    vector<int> temp(2);
	    while(!ss.eof())
	    {
	        ss >> temp[j];
	        ++j;
	    }
	    
	    cout << checkPower(temp) << endl;
	}
	return 0;
}
