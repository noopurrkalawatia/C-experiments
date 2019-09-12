#include <iostream>
using namespace std;
void insertSort(int a[], int n)
{
    int i,j,v;

    for(i = 1; i <= n - 1; ++i)
    {
        v = a[i];
        j = i;

        while(a[j-1] > v && j >= 1)
        {
            a[j] = a[j-1];
            --j;
        }

        a[j] = v;
    }
}
int main(void)
{
    int a[5] = {5,1,3,2,4};
    insertSort(a,5);
    for(int i = 0 ; i < 5 ; ++i)
    {
        cout << a[i] << endl;
    }

        return 0;
}
