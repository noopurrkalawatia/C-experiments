class Solution {
public:
    string reverseWords(string s) 
    {
        stringstream ss(s);
        string inter;
        
        vector<string> input;
        char delim = ' ';
        
        while(getline(ss,inter,delim))
        {
            if(inter.size() > 0)
            {
                input.push_back(inter);
            }
        }
    
        string result;
        
        for(int i = input.size() - 1;i >= 0; --i)
        {
            result += input[i];
            result += " ";
        }
       
        result.erase(result.begin()+result.size()-1, result.end());
        return result;
    }
};
