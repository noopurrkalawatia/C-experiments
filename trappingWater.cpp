class Solution {
public:
    int trap(vector<int>& height) 
    {
        if(height.size() < 1)
        {
            return 0;
        }
        
        
        int left = 0;
        int right = height.size() - 1;
       
        int p1 = height[left];
        int p2 = height[right];
        int leftMax = 0, rightMax = 0;
    
        int result = 0;
         
        while(left < right)
        {
            if(height[left] < height[right])
            {
                if(height[left] >= leftMax)
                {
                    leftMax = height[left];
                }
                else
                {
                    result += leftMax - height[left];
                }
                ++left;
            }
            
            else
            {
                if(height[right] >= rightMax)
                {
                    rightMax = height[right];
                }
                
                else
                {
                    result += rightMax - height[right];
                }
                
                --right;
            }
        }
        
        return result;
    }
};
