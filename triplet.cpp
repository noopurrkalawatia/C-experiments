#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int find(int target, int start, int end, vector<int> nums)
{
    unordered_map<int,int> integer_map;
    for(int i = start; i < end; ++i)
    {
        if(integer_map.find(target - nums[i]) != integer_map.end())
        {
            return 1;
        }
        else
        {
            integer_map.insert({nums[i],i});
        }
    }
    return 0;
}
void calc(vector<int> nums)
{
    for(int i = 0; i < nums.size(); ++i)
    {
        nums[i] = pow(nums[i],2);
    }
    sort(nums.begin(),nums.end());
    
    for(int j = nums.size() - 1; j > 0; --j)
    {
        int sum = nums[j],i = 0;
        int result = find(sum,i,j,nums);
        if(result == 1)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main() 
{
	int noOfTestcases = 0;
	
	cin >> noOfTestcases;
	if(noOfTestcases == 0) noOfTestcases = 1;
	vector<int> nums;

	for(int i = 0 ; i < noOfTestcases; ++i)
	{
	    int size = 0;
	    cin >> size;
	    for(int j = 0 ;j < size;++j)
	    {
	        int k = 0;
	        cin >> k;
	        nums.push_back(k); 
	    }
	    
	    calc(nums);
	}
	return 0;
}
