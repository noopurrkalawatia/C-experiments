class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        int sum = 0;
        for(int n : nums)
        {
            sum += n;
        }
        if(k <= 0 || (sum % k != 0))
        {
            return false;
        }
        vector<int>visited(nums.size(),0);
        return canPartition(nums,k,0,0,visited,sum / k);
    }
    
    bool canPartition(vector<int> nums, int k, int start_index, int curr_sum, vector<int>visited,int target)
    {
        if(k == 1) return true;
        if(curr_sum > target) return false;
        if(curr_sum == target)
        {
            return(canPartition(nums,k-1,0,0,visited,target));
        }
        for(int i = start_index; i < nums.size(); ++i)
        {
            if(visited[i] == 0)
            {
                visited[i] = 1;
                if(canPartition(nums,k,i+1,curr_sum + nums[i],visited,target))
                {
                    return true;
                }
                visited[i] = 0;
            }
        }
        return false;
    }
};
