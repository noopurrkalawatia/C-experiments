#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int noOfTestcases;
	cin >> noOfTestcases;
	while(noOfTestcases--){
	    int size;
	    cin >> size;
	    vector<int> input(size);
	    for(int i = 0;i < size;++i)
	    {
	        cin>>input[i];
	    }
	    for(int i = 0;i < size-1;++i) 
	    {
	        if(input[i+1] < input[i])
	        {
	            cout << input[i+1] << " ";
	        } 
	        else 
	        {
	            cout << "-1 ";
	        }
	    }
	    cout << "-1\n";
	}
	return 0;
}
