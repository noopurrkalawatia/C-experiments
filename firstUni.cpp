class Solution {
public:
    int firstUniqChar(string s) 
    {
        unordered_map<char,int> myMap;
        
        for(char c : s)
        {
            myMap[c]++;
        }
        
        for(int i = 0; i < s.length(); ++i)
        {
            if(myMap[s[i]] == 1)
            {
                return i;
            }
        }
        
        return -1;
    }
};
