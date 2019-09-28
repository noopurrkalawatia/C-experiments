
#include <iostream>
#include <algorithm>

using namespace std;


int calculate(int arr[], int dep[], int n)
{
    sort(arr,arr + n);
    sort(dep,dep + n);
    
    int i = 0, j = 0, platform = 0, result = 0;
    
    
    while(i < n && j < n)
    {
        if(arr[i] <= dep[j])
        {
            ++platform;
            ++i;
            
            if(platform > result)
            {
                result = platform;
            }
        }
        
        else
        {
            platform--;
            j++;
        }
    }
    
    return result;
}

int main()
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800}; 
	int dep[] = {910, 1200, 1120, 1130, 1900, 2000}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Minimum Number of Platforms Required = "
		<< calculate(arr, dep, n);
    return 0;
}
