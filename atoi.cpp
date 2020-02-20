class Solution {
public:
    int myAtoi(string str) 
    {
        long result = 0;
        int indicator = 1;
        
        int i = str.find_first_not_of(" ");
        
        if(i >= str.size())
        {
            return 0;
        }
        
        if(str[i] == '-' || str[i] == '+')
        {
            indicator = (str[i] == '-') ? -1 : 1;
            ++i;
        }
        
        while(i < str.size() && isdigit(str[i]))
        {
            result = result * 10 + str[i] - '0';
            if(indicator == 1)
            {
                if(result >= INT_MAX)
                {
                    result = INT_MAX;
                    break;
                }
                
            }
            else if(indicator == -1)
            {
                if(result * indicator <= INT_MIN)
                {
                    result = (long)INT_MIN * indicator;
                    break;
                }
            }
            ++i;
        }
        
        
        return (int) (result * indicator);
    }
};
