class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> numSet;
        for(int i = 0 ; i < nums.size(); ++i)
        {
            if(numSet.find(nums[i]) == numSet.end())
            {
                numSet.insert(nums[i]);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
