#include <iostream>
using namespace std;
#include <stdio.h>
#include <queue>

#define MAX_CHAR 26
struct Element
{
    public:
    int freq;
    char ch;
    
    int operator<(const Element& e) const
    {
        return(freq < e.freq);
    }
    
    Element(int value, char c)
    {
        freq = value;
        ch = c;
    }
    
};

template<typename T> void print_queue(T q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

std::ostream& operator<<(std::ostream& os,const Element& e)
{
    os << "The frequency is " << e.freq << endl;
    os << "The character is " << e.ch << endl;
    return os;
}

void testString(string input)
{
    priority_queue<Element> charQueue;
    string output;
	
	int freqSet[MAX_CHAR] = {0};
	for(int i = 0 ; i < input.size() ; ++i)
	{
	    ++freqSet[input[i] - 'a'];
	}
	
	//insert the elements in a priority queue
	for(char c = 'a' ; c <= 'z' ; ++c)
	{
	    if(freqSet[c - 'a'])
	    {
	        //Element here is the constructor of the structure.
	        charQueue.push(Element(freqSet[c - 'a'], c));
	    }
	}
	
	Element previous = {-1, '$'};
	
	
	while(!charQueue.empty())
	{
	    Element current = charQueue.top();
	    charQueue.pop();
	    
	    output += current.ch;
	    
	    if(previous.freq > 0)
	    {
	        charQueue.push(previous);
	    }
	    
	    --current.freq;
	    previous = current;
	    print_queue(charQueue);
	    
	}
	
	cout << output << endl;
	
	if(output.size() == input.size())
	{
	    cout << "1" << endl;
	}
	else
	{
	    cout << "0" << endl; 
	}
}

int main() 
{
	string input;
	int noTestCases = 0;
	cin >> noTestCases;
	
	for(int i = 0 ; i < noTestCases ; ++i )
	{
	    cin >> input;
	    testString(input);
	}
	return 0;
}
