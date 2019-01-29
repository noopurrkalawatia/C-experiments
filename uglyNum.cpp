#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int noOfTestcases;
    cin >> noOfTestcases;
    int input[noOfTestcases];
    int maxValue=1;
    
    for(int i = 0;i < noOfTestcases; i++)
    {
        cin >> input[i];
        if(input[i] > maxValue) 
        {
            maxValue = input[i];
        }
    }
        int n = maxValue;
        long long ugly[n];
        ugly[0] = 1;
        int i2 = 0,i3 = 0,i5 = 0;
        long long next_ugly = min(min(2*ugly[i2],3*ugly[i3]),5*ugly[i5]);
        for(int i=1;i<n;i++)
        {
            ugly[i] = next_ugly;
            
            if(next_ugly == 2*ugly[i2]) i2++;
            if(next_ugly == 3*ugly[i3]) i3++;
            if(next_ugly == 5*ugly[i5]) i5++;
            
            next_ugly=min(2*ugly[i2],min(3*ugly[i3],5*ugly[i5]));
        }
        
        for(int i = 0; i < noOfTestcases; i++)
        {
            int num = input[i];
            cout << ugly[num-1] << endl;
        }
    return 0;
}
