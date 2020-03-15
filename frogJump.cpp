class Solution {
public:
    bool canCross(vector<int>& stones) 
    {
        unordered_map<int,unordered_set<int>> myStoneMap;
        for(int i = 0 ; i < stones.size(); ++i)
        {
            myStoneMap[stones[i]] = unordered_set<int>();
        }
        
        myStoneMap[0].insert(0);
        
        for(int i = 0 ; i < stones.size(); ++i)
        {
            for(auto k : myStoneMap.at(stones[i]))
            {
                for(int step = k - 1; step <= k + 1; ++step)
                {
                    if(step > 0 && myStoneMap.find(step + stones[i]) != myStoneMap.end())
                    {
                        myStoneMap.at(step + stones[i]).insert(step);
                    }
                }
            }
        }
        
        return (myStoneMap.at(stones[stones.size() - 1]).size() > 0);
    }
};
