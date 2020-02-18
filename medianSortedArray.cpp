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
            
            /* Only the condition aCount > 0 is required because if the number of elements 
            contributed by A is positive it is implied that bCount is 
            positive. */
            if(aCount > 0 && A[aCount - 1] > B[bCount])
            {
                //Decrease the contribution of A to the lefthalf of the the Array
                amaxCount = aCount - 1;
            }
            
            /* Only if the aCount is lesser than the A.size can we ensure that bCount - 1 
            is a positive number and can be evaluated thus this condition is                         
            sufficient to check for both of them. */
            else if(aCount < A.size() && B[bCount - 1] > A[aCount])
            {
                //Increase the contribution of A to the leftHalf of the array
                aminCount = aCount + 1;
            }
            
            else
            {   //if both the above cases are not true that means we have found the
                //median of the sorted arrays. 
                leftLimitNum = (aCount == 0) ? B[bCount - 1] : 
                                (bCount == 0) ? A[aCount - 1] :  
                                max(A[aCount - 1],B[bCount-1]);
                
                //for the array which consists of odd number of elements.
                if(maxLength % 2 != 0)
                {
                    return leftLimitNum;
                }
                
                //For even number of elements we have to compute two middle most 
                //elements of the array. 
                rightLimitNum = (aCount == A.size()) ? B[bCount] : 
                                (bCount == B.size()) ? A[aCount] :  
                                min(A[aCount],B[bCount]);
                
                return ((leftLimitNum + rightLimitNum) / 2.0);
            }
        }
        return -1;
    }
};
