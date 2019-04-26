#include<iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRU
{
    int csize;
    unordered_map<int, list<int>::iterator > map_Nodes;
    list<int> listNodes;

public:
    LRU(int size)
    {
        csize = size;
    }

    void displayLRU()
    {
        for(auto i = listNodes.begin(); i != listNodes.end(); ++i)
        {
            cout << *i ;
        }

        cout << endl;
    }

    void refer(int x)
    {
        if(map_Nodes.find(x) == map_Nodes.end())
        {
            if(listNodes.size() == csize)
            {
                int last = listNodes.back();
                map_Nodes.erase(last);
                listNodes.pop_back();
            }
        }

        else
        {
            listNodes.remove(x);
        }
        
        listNodes.push_front(x);
        map_Nodes[x] = listNodes.begin();
    }
};

int main() 
{ 
    LRU ca(4); 
  
    ca.refer(1); 
    ca.refer(2); 
    ca.refer(3); 
    ca.refer(1); 
    ca.refer(4); 
    ca.refer(5); 
    ca.displayLRU(); 
  
    return 0; 
} 
