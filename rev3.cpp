class Solution {
public:
    string reverseWords(string s) 
    {
        if(s.size() == 0)
        {
            return s;
        }
        stringstream ss(s);
        char delim = ' ';
        string inter;
        
        vector<string> input;
        string result;
        
        while(getline(ss,inter,delim))
        {
            reverse(inter.begin(), inter.end());
            result += inter + delim;
            input.push_back(inter);  
        }
        
        result.erase(result.begin() + result.size() - 1 , result.end());
        return result;
    }
};
