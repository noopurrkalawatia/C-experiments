#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

#define MAX_CHAR 26

int computeValue(string input, int value)
{
    int size = input.size();
    int result = 0, k = 0;
    if(value >= size)
    {
        return 0;
    }
    
    //Form an array of frequencies of every character in the string.
    int freq[MAX_CHAR] = {0};
    
    for(int i = 0 ; i < size ; ++i)
    {
        ++freq[input[i] - 'a'];
    }
    
    //form a priority queue for each frequency of the character
    priority_queue<int> freQueue;
    for(int j = 0 ; j < MAX_CHAR ; ++j)
    {
        freQueue.push(freq[j]);
    }
    
    //pop the new decremented frequency
    while(value > 0)
    {
        int temp = freQueue.top();
        freQueue.pop();
        temp = temp - 1;
        freQueue.push(temp);
        --value;
    }
    
    while(!freQueue.empty())
    {
        int temp = freQueue.top();
        result = result + (temp * temp);
        freQueue.pop();
    }
    
    return result;
}

int main() 
{
	int noOfTestcases = 0, result = 0, value = 0; 
	cin >> noOfTestcases;
	string input;
	for(int i = 0 ; i < noOfTestcases ; ++i)
	{
	    cin.ignore();
	    getline(cin,input);
	    cin >> value;
	    result = computeValue(input,value);
	    cout << result << endl;
	}
	return 0;
}
