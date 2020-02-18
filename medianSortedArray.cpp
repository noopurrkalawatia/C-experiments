class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        //vector A will always have the elements of the shorter vector
        //vector B will always have the elements of the longer vector
        //acount refers to the number of elements contributed by A
        //acount refers to the number of elements contributed by B
        // amin and amax refers to the minimum and maximum elements it can contribute.
        
        int maxLength = nums1.size() + nums2.size();
        int leftHalfLength = (maxLength + 1) / 2;
        vector<int> A(nums1);
        vector<int> B(nums2); 
        
        if(nums1.size() > nums2.size())
        {
            A.swap(B);
        } 

        
        int aminCount = 0;
        int amaxCount = A.size();
        
        int aCount = 0, bCount = 0, leftLimitNum = 0, rightLimitNum = 0;
        
        while(aminCount <= amaxCount)
        {
            aCount = aminCount + ((amaxCount - aminCount)/2);
            bCount = leftHalfLength - aCount;
            
            if(aCount > 0 && A[aCount - 1] > B[bCount])
            {
                amaxCount = aCount - 1;
            }
            
            else if(aCount < A.size() && B[bCount - 1] > A[aCount])
            {
                aminCount = aCount + 1;
            }
            
            else
            {                
                leftLimitNum = (aCount == 0) ? B[bCount - 1] : 
                                (bCount == 0) ? A[aCount - 1] :  
                                max(A[aCount - 1],B[bCount-1]);
                
                if(maxLength % 2 != 0)
                {
                    return leftLimitNum;
                }
                
                rightLimitNum = (aCount == A.size()) ? B[bCount] : 
                                (bCount == B.size()) ? A[aCount] :  
                                min(A[aCount],B[bCount]);
                
                return ((leftLimitNum + rightLimitNum) / 2.0);
            }
        }
        return -1;
    }
};
