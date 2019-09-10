#include<iostream>

using namespace std;
template<class T>
class smartPtr
{
    public:
    T *ptr;

    explicit smartPtr(T *p = NULL)
    {
        ptr = p;
    }

    T& operator*()
    {
        return *ptr;
    }

    T* operator->()
    {
        return ptr;
    }

};
int main(void)
{
    smartPtr<int> ptr(new int());
    *ptr = 30;

    cout << *ptr << endl;
    return 0;
}