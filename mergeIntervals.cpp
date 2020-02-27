
bool compareInterval(vector<int> a, vector<int> b)
{
    return(a[0] < b[0]);
}  

class Solution {
public:
  
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),compareInterval);
        
        vector<vector<int>> mergedIntervals;
        int current = 0;
        for(auto it : intervals)
        {
            if(mergedIntervals.empty() || mergedIntervals.back()[1] < it[0])
            {
                mergedIntervals.push_back(it);
            }
            
            else
            {
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1],it[1]);
            }
        }
        
        return mergedIntervals;
    }
};
