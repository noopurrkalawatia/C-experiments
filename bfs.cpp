#include <iostream>
#include <list>

using namespace std;
class Graph
{
    int noOfVertices;

    list<int> *adj;

public:
    Graph(int v)
    {
        noOfVertices = v;
        adj = new list<int>[noOfVertices];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void bfs(int source)
    {
        bool *visited = new bool[noOfVertices];
        for(int i = 0; i < noOfVertices; ++i)
        {
            visited[i] = false;
        }

        list<int> queue;

        //mark the node that you recived in the method as  visited. Change the 
        //value as true in the adjacency list representation.

        visited[source] = true;
        queue.push_back(source);

        list<int>::iterator i;
        cout << "Data is" << endl;
        while(!queue.empty())
        {
            source = queue.front();
            cout << source << " "; 
            queue.pop_front();

            for(i = adj[source].begin(); i != adj[source].end(); ++i)
            {
                //cout << "Person is " << *i <<endl;
                if(!visited[*i])
                {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
        cout << endl;
    }
};

int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(5); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4); 
    g.addEdge(4, 1);
    g.addEdge(4, 2);
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 

    g.bfs(2); 
  
    return 0; 
} 
