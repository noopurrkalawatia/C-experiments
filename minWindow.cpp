class Solution {
public:
    string minWindow(string s, string t) 
    {
        if(s.size() == 0 || t.size() == 0)
        {
            return "";
        }
        
        unordered_map<char,int> mytMap;
        int numUniqueChars = 0;
        
        for(int i = 0; i < t.size(); ++i)
        {
            int count = 0;
            auto it = mytMap.find(t[i]);
            if(it != mytMap.end())
            {
               ++it->second;
            }
            else
            {
                mytMap[t[i]] = count + 1;
                ++numUniqueChars;
            }
        }
        
        int formed = 0;
        //answer parameters -> window length, left, right
        vector<int> myParameters = {-1,0,0};
        //form the map for the unique characters in the string S.
        unordered_map<char,int> mysMap;
        int left = 0;
        int right = 0;
        
        while(right < s.size())
        {
            char k = s[right];
            int count = 0;
            auto itr = mysMap.find(k);
            if( itr != mysMap.end())
            {
                ++itr->second;
            }
            else
            {
                mysMap[k] = count + 1;
            }
            
            if(mytMap.find(k) != mytMap.end() && mysMap.at(k) == mytMap.at(k))
            {
                ++formed;
            }
            
            while(left <= right && formed == numUniqueChars)
            {
                k = s[left];
                if(right - left + 1 < myParameters[0] || myParameters[0] == -1)
                {
                    myParameters[0] = right - left + 1;
                    myParameters[1] = left;
                    myParameters[2] = right;
                }
                
                int tempCount = mysMap.at(k);
                mysMap[k] = tempCount - 1;
                
                if(mytMap.find(k) != mytMap.end() && mysMap.at(k) < mytMap.at(k))
                {
                    --formed;
                }
                
                ++left;
            }
            
            ++right;
        }
        
        
        return(myParameters[0] > -1 ? s.substr(myParameters[1],myParameters[0]) : "");
    }
};
