class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        int leastSum = nums[0] + nums[1] + nums[2];
        
        for(unsigned int i = 0 ; i < nums.size() - 2; ++i)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                
                if(abs(sum - target) < abs(leastSum - target))
                {
                    leastSum = sum;
                }
                
                if(sum < target)
                {
                    ++j;
                }
                else
                {
                    --k;
                }
            }
        }
        
        return leastSum;
    }
};
