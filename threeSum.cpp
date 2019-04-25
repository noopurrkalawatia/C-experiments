class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        
        for(unsigned int i = 0 ; i < nums.size(); ++i)
        {
            if(i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }
            int l = i + 1, r = nums.size() - 1;
            
            while(l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > 0)
                {
                    --r;
                }
                else if(sum < 0)
                {
                    ++l;
                }
                else
                {
                    result.push_back({nums[i],nums[l],nums[r]});
                    while(l + 1 < nums.size() && nums[l] == nums[l+1])
                    {
                        ++l;
                    }
                    while(r - 1 > 0 && nums[r] == nums[r-1])
                    {
                         --r;
                    }
                    ++l;
                    --r; 
                }
            }
        }
        return result;
}
};
