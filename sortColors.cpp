class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        if(nums.size() == 0)
        {
            return;
        }
        int left = 0;
        int right = nums.size() - 1;
        int moving = 0;
        
        while(moving <= right)
        {
            if(2 == nums[moving])
            {
                swap(nums[moving],nums[right]);
                --right;
            }
            else if(0 == nums[moving])
            {
                swap(nums[moving],nums[left]);
                ++left;
                ++moving;
            }
            else
            {
                ++moving;
            }
        }
    }
};
