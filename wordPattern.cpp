class Solution {
public:
    bool wordPattern(string pattern, string str) 
    {
        unordered_map<char,string> my_map;
        unordered_map<char,string>::iterator it;

        
        vector<string> tokens; 
        stringstream check1(str); 
        string intermediate; 
      
        while(getline(check1, intermediate, ' ')) 
        { 
            tokens.push_back(intermediate); 
        }
        
        
        if(tokens.size() != pattern.size())
        {
            return false;
        }
         
        for (itr = umap.begin(); itr != umap.end(); itr++) 
        { 
           
        } 
        for(int i = 0 , j = 0 ; i < pattern.size() && j < tokens.size(); ++i,++j)
        {
            it = my_map.find(pattern[i]);
            if(it == my_map.end())
            {
                if(stringSet.find(tokens[j]) == stringSet.end())
                {
                    stringSet.insert(tokens[j]);
                    my_map.insert({pattern[i],tokens[j]});
                }
                else
                {
                    return false;
                }
            }
            else
            {
                cout << "else case : " << " inside : pattern is " << pattern[i] << "string is " << tokens[j] << endl;
                if(it->second != tokens[j])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
