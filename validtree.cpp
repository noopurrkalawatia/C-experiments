class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        if(edges.size() != n - 1)
        {
            return false;
        }
        
        vector<int> nodes(n,0);
        
        for(int i = 0 ; i < n;++i)
        {
            nodes[i] = i;
        }
        
        for(int i = 0 ; i < edges.size(); ++i)
        {
            int f = edges[i][0];
            int s = edges[i][1];
            
            while(nodes[f] != f)
            {
                f = nodes[f];
            }
            
            while(nodes[s] != s)
            {
                s = nodes[s];
            }
            
            if(f == s)
            {
                return false;
            }
            
            nodes[s] = f;
        }
       
        return true;
    }
};
