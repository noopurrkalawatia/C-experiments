#include <iostream>

using namespace std;
void myCopy(char arr[], char arr2[])
{
    int i;
    for(i = 0 ; arr[i] != '\0' ;++i)
    {
        arr2[i] = arr[i];
    }
    arr[i] = '\0';
}
int main() 
{
    char s1[10] = "Noopur";
    char s2[10] = "Ganesh";
    myCopy(s1,s2);
    cout << s2 << endl;
    return 0;
}
