class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        map<string,vector<string>> myMap;
        vector<vector<string> > result;
        
        for(int i = 0 ; i < strs.size(); ++i)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            
            auto it = myMap.find(temp);
            if(it != myMap.end())
            {
                it->second.push_back(strs[i]);
            }
            else
            {
                vector<string> tempVec;
                tempVec.push_back(strs[i]);
                myMap[temp] = tempVec;
            }
        }
        
        for(auto it = myMap.begin(); it != myMap.end(); ++it)
        {
            result.push_back(it->second);
        }
        
        return result;
    }
};
