#include <iostream>

using namespace std;
void myCopy(char arr[], char arr2[],int index)
{
    if(arr[index] == '\0')
    {
        return;
    }
    else
    {
        arr2[index] = arr[index];
        ++index;
        myCopy(arr,arr2,index);
    }
}
int main() 
{
    char s1[10] = "Noopur";
    char s2[10] = "Ganesh";
    myCopy(s1,s2,0);
    cout << s2 << endl;
    return 0;
}
