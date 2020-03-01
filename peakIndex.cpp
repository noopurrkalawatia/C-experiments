class Solution 
{
public:
    int peakIndexInMountainArray(vector<int>& A) 
    {
        int low = 0;
        int high = A.size() - 1;
        int mid = 0; 
        
        while(low < high)
        {
            mid = low + (high - low) / 2;
            if(A[mid] < A[mid + 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        
        return low;
    }
};
