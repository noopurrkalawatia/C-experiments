class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.size() == 0)
        {
            return 0;
        }
        
        int index[256];
        for (int i = 0; i < 256; ++i)
        {
		    index[i] = -1; 
        }

        int max_len = 1;
        int curr_len = 1;
        int prev_index;
        
        index[s[0]] = 0;
        
        for(int i = 1 ; i < s.size(); ++i)
        {
            prev_index = index[s[i]];
            if(index[s[i]] == -1 || i - prev_index > curr_len)
            {
                curr_len++;
            }
            else
            {
                if(curr_len > max_len)
                {
                    max_len = curr_len;
                }
                curr_len = i - prev_index;
            }
            index[s[i]] = i;
        }
        return curr_len > max_len ? curr_len : max_len;   
    }
};
