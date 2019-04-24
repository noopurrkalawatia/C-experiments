#include <iostream>
#include <list>
#include <stack>
using namespace std;
class Graph
{
    int noOfVertices;

    list<int> *adj;

    void topologicalSortHelper(int v, bool visited[], stack<int> &Stack);
    public:
    Graph(int v);
    void addEdge(int v, int w);
    void topologicalSort();
};

Graph::Graph(int v)
{
    noOfVertices = v;
    adj = new list<int>[noOfVertices];
}

void Graph::addEdge(int v,int w)
{
    
    if(adj != NULL)
    {
        cout << "The edge is " << v << "The other vertex is : " << w << endl;
        adj[v].push_back(w);
    }
}

void Graph::topologicalSortHelper(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;

    list<int>::iterator i;

    for(i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if(!visited[*i])
        {
            topologicalSortHelper(*i,visited, Stack);
        }
    }
    Stack.push(v);
}

void Graph::topologicalSort()
{
    stack<int> Stack;

    bool *visited  = new bool[noOfVertices];
    for(int i = 0 ; i < noOfVertices; ++i)
    {
        visited[i] = false;
    }

    for(int i= 0 ; i < noOfVertices; ++i)
    {
        if(visited[i] == false)
        {
            topologicalSortHelper(i,visited,Stack);
        }
    }

    while(Stack.empty() == false)
    {
        cout << Stack.top();
        Stack.pop();
    }
}


int main()
{
    Graph g1(6);
    g1.addEdge(5,0);
    g1.addEdge(5,1);
    g1.addEdge(4,0);
    g1.addEdge(4,1);
    g1.addEdge(3,1);
    g1.addEdge(2,3);

    g1.topologicalSort();
    return 0;
}

