class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> mySet;
        unordered_set<int> mySet2;
        vector<int> result;
        
        for(int i = 0 ; i < nums1.size(); ++i)
        {
            if(mySet.find(nums1[i]) == mySet.end())
            {
                mySet.insert(nums1[i]);
            }
        }
        
        for(int i = 0 ; i < nums2.size(); ++i)
        {
            if(mySet.find(nums2[i]) != mySet.end() && mySet2.find(nums2[i]) == mySet2.end())
            {
                mySet2.insert(nums2[i]);
                result.push_back(nums2[i]);
            }
        }
        
        return result;
    }
};
