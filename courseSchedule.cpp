class Solution {
public:
    
    bool isCyclic(int i, vector<bool> &recStack, vector<bool>& visited,vector<vector<int> >& adjList)
    {
        if(recStack[i])
        {
            return true;
        }

        visited[i] = true;
        recStack[i] = true;
        
        for(int j = 0 ; j < adjList[i].size(); ++j)
        {
            if(isCyclic(adjList[i][j],recStack,visited,adjList))
            {
                return true;
            }
        }
        
        recStack[i] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adjList(numCourses);
        
        for(int i = 0 ; i < prerequisites.size(); ++i)
        {
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<bool> recStack(numCourses,false);
        vector<bool> visited(numCourses,false);
        
        for(int i = 0 ; i < numCourses; ++i)
        {
            if(visited[i] != true)
            {
                if(isCyclic(i,recStack,visited,adjList))
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};
