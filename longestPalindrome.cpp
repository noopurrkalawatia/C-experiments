#include <iostream>
#include <string>
using namespace std;

void calcPalindrome(string test)
{
    int n = test.length();
    if(n == 0)
    {
        return; 
    }

    bool table[n][n];
    int start = 0;
    int maxLength = 0;
    
    for(int i = 0 ; i < n; ++i)
    {
        table[i][i] = true;
        maxLength = 2;
        start = i;
    }
    
    //for strings for length 2.
    for(int i = 0; i < n-1;++i)
    {
        if(test[i] == test[i + 1])
        {
            table[i][i+1] = true;
        }
    }
    
    //start evaluating for the index 3
    for(int k = 3; k <= n ; ++k)
    {
        for(int i = 0; i < n - k + 1; ++i)
        {
            int j = i + k - 1;
            
            if(table[i+1][j-1] == true && test[i] == test[j])
            {
                table[i][j] = true;
                start = i;
                maxLength = k;
            }
        }
    }
    
    for(int i = start; i < start + maxLength; ++i)
    {
        cout << test[i];
    }

}
int main() 
{
    int noOfTestcases = 0;
    cin >> noOfTestcases;
    if(noOfTestcases == 0)
    {
        noOfTestcases = 1;
    }
	string test;
	cin.ignore();
	for(int i = 0 ; i < noOfTestcases ; ++i)
	{
	    getline(cin,test);
	    calcPalindrome(test);
	}
	return 0;
}
