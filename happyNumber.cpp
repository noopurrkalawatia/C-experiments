class Solution {
public:
    int getNextSum(int n)
    {
        int totalSum = 0;
        
        while(n > 0)
        {
            int d = n % 10;
            totalSum += d * d;
            n = n / 10;
        }
        
        return totalSum;
    }
    
    bool isHappy(int n) 
    {
        unordered_set<int> mySet;
        
        while(n!= 1 && mySet.find(n) == mySet.end())
        {
            mySet.insert(n);
            n = getNextSum(n);
        }
        
        return (n == 1);
    }   
    
};
