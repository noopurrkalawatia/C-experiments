class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> result;
        if(nums.size() == 0)
        {
            return result;
        }
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0 ; i < nums.size(); ++i)
        {
            int target3 = target - nums[i];
            
            for(int j = i + 1; j < nums.size(); ++j)
            {
                int target2 = target3 - nums[j];
                
                int front = j + 1;
                int back = nums.size() - 1;
                
                while(front < back)
                {
                    int twoSum = nums[front] + nums[back];
                    if(twoSum == target2)
                    {
                        vector<int> quadra(4,0);
                        quadra[0] = nums[i];
                        quadra[1] = nums[j];
                        quadra[2] = nums[front];
                        quadra[3] = nums[back];
                        result.push_back(quadra);
                        
                        while(front < back && nums[front] == quadra[2])
                        {
                            ++front;
                        }
                        
                        while(front < back && nums[back] == quadra[3])
                        {
                            --back;
                        }
                    }
                    
                    else if(twoSum > target2)
                    {
                        --back;
                    }
                    
                    else
                    {
                        ++front;
                    }
                }
                
                while(j + 1 < nums.size() && nums[j] == nums[j + 1])
                    ++j;
            }
            
            while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                ++i;
        }
        
        return result;
    }
};
