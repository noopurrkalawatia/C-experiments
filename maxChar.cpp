#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int noOfTestcases;
    cin >> noOfTestcases;
    for(int i = 0 ; i < noOfTestcases; ++i)
    {
        string input;
        cin >> input;
        
        int res = -1,position,size = input.size();
        for(int j = 0;j < size; j++)
        {
            int position = input.find_last_of(input[j]);
            cout << "Position is : "<<position << endl;
            if( position != j )
            {
                if((position - j - 1) > res)
                {
                    res = position - j - 1;
                }
            }
        }
        cout << res << endl;
    }
	return 0;
}
