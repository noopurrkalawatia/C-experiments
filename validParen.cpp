class Solution {
public:
    bool isValid(string s) 
    {
        if(s.size() == 1)
        {
            return false;
        }
        
        stack<char> myStack;
        unordered_map<char,char> myMap;
        
        myMap[')'] = '(';
        myMap['}'] = '{';
        myMap[']'] = '[';
        
        for(int i = 0 ; i < s.size(); ++i)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                myStack.push(s[i]);
            }
            
            else
            {
                if(myStack.size() > 0)
                {
                    if(myStack.top() != myMap.find(s[i])->second)
                    {
                        return false;
                    }
                
                    myStack.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        
        return (myStack.size() > 0 ? false : true);
    }
};
