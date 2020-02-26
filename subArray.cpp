class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cumSum = 0; // cumulated sum
        unordered_map<int,int> myMap; // prefix sum recorder
        int cnt = 0; // number of found subarray
        myMap[0]++; // to take into account those subarrays that begin with index 0
        for(int i = 0; i < nums.size(); ++i)
        {
            cumSum += nums[i];
            cnt += myMap[cumSum-k];
            myMap[cumSum]++;
        }
        return cnt;
    }
};
