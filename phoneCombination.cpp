class Solution {
public:
    vector<string> result;
    void generateCombinations(string digits,unordered_map<string,string> myMap,string combination)
    {
        if(digits.size() == 0)
        {
            result.push_back(combination);
        }
        else
        {
            string temp = digits.substr(0,1);
            string op = myMap.at(temp);
            
            for(int i = 0 ; i < op.size(); ++i)
            {
                string letter = op.substr(i,1);
                generateCombinations(digits.substr(1),myMap,combination+letter);
            }
        }
    }
    
    vector<string> letterCombinations(string digits) 
    {
        if(digits.size() == 0)
        {
            return result;
        }
        unordered_map<string, string> myMap;
        myMap["2"] = "abc";
        myMap["3"] = "def";
        myMap["4"] = "ghi";
        myMap["5"] = "jkl";
        myMap["6"] = "mno";
        myMap["7"] = "pqrs";
        myMap["8"] = "tuv";
        myMap["9"] = "wxyz";
        
        string combination;
        generateCombinations(digits,myMap,combination);
        return result;
    }
};
