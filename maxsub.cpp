class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int max_sum = INT_MIN;
        int evaluate_sum = 0;
        
        for(int i = 0 ; i < nums.size(); ++i)
        {
            evaluate_sum = evaluate_sum + nums[i];
            
            if(evaluate_sum > max_sum)
            {
                max_sum = evaluate_sum;
            }
            
            if(evaluate_sum < 0)
            {
                evaluate_sum = 0;
            }
        }
        return max_sum;
    }
};
