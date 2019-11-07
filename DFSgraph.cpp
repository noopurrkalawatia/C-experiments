#include<iostream>
#include<vector>

using namespace std;

void addEdge(vector<int> adj[],int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSUtil(vector<bool> &visited,int v, vector<int> adj[])
{
    visited[v] = true;

    cout << v << endl;

    for(int index = 0; index < adj[v].size(); ++index)
    {
        if(visited[adj[v][index]] == false)
        {
            DFSUtil(visited,adj[v][index],adj);
        }
    }
}

void DFS(vector<int> adj[], int V)
{
    vector<bool> visited(V,false);

    for(int index = 0 ; index < V; ++index)
    {
        if(visited[index] == false)
        {
            DFSUtil(visited,index,adj);
        }
    }
}

int main(void)
{
    int V = 5;
    vector<int> adj[V];

    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 

    DFS(adj, V); 
    return 0; 
}
