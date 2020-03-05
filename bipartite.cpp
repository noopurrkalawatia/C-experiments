
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        stack<int> myGraph;
        unordered_map<int,int> myColorMap;
        
        int noOfVertices = graph.size();
        
        for(int start = 0 ; start < noOfVertices; ++start)
        {
            myColorMap[start] = 0;
            myGraph.push(start);
        }

        while(!myGraph.empty())
        {
            int temp = myGraph.top();
            myGraph.pop();
            
            auto it = myColorMap.find(temp);
            if(0 == it->second)
            {
                myColorMap[temp] = 1;
            }
            
            int currentcolor = myColorMap[temp];
            
            for(int i = 0; i < graph[temp].size();++i)
            {
                auto it = myColorMap.find(graph[temp][i]);
                if(0 == it->second)
                {
                    myColorMap[graph[temp][i]] = (currentcolor == 1) ? -1 : 1;
                    myGraph.push(graph[temp][i]);
                }
                
                else if(currentcolor == it->second)
                {
                    return false;
                }
            }
        } 
        
        return true;
    }
};
