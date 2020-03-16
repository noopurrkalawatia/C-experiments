class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        queue<int> myIndexQueue;
        unordered_set<string> myDict(wordDict.begin(),wordDict.end());
        
        vector<int> visited(s.size(),0);
        myIndexQueue.push(0);
        while(!myIndexQueue.empty())
        {
            int start = myIndexQueue.front();
            myIndexQueue.pop();
            
            if(visited[start] == 0)
            {
                for(int end = start; end < s.size(); ++end)
                {
                    size_t strlength = end - start + 1;
                    if(myDict.find(s.substr(start,strlength)) != myDict.end())
                    {
                        myIndexQueue.push(end + 1);
                        if(end == s.length() - 1)
                        {
                            return true;
                        }
                    }
                }
                visited[start] = 1;
            }
        }
        
        return false;
    }
};
