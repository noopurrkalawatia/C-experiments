/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInArrayLeft(MountainArray &mountainArr, int low, int high,int target)
    {
        int mid = 0;
        int midVal = 0;
        
        while(low <= high)
        {
            mid = low + (high - low) / 2;
            midVal = mountainArr.get(mid);
            if(midVal == target)
            {
                return mid;
            }
            
            else if(midVal < target)
            {
                low = mid + 1;
            }
            
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
    
    int findInArrayRight(MountainArray &mountainArr, int low, int high,int target)
    {
        int mid = 0;
        int midVal = 0;
        
        while(low <= high)
        {
            mid = low + (high - low) / 2;
            midVal = mountainArr.get(mid);
            if(midVal == target)
            {
                return mid;
            }
            
            else if(midVal < target)
            {
                high = mid - 1;
            }
            
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) 
    {
        int low = 0 ;
        int high = 0;
        high = mountainArr.length() - 1;
        int mid;
        while(low < high)
        {
            mid = low + (high - low) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1))
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            } 
        }
        
        int peak = low;
        
        if(mountainArr.get(peak) == target)
        {
            return peak;
        }
        
        int res1 = findInArrayLeft(mountainArr,0,peak - 1,target);
        int res2 = findInArrayRight(mountainArr,peak+1,mountainArr.length() - 1,target);

        return (res1 == -1 ? res2 : 
                res2 == -1 ? res1 : 
                min(res1,res2));
    }
};
