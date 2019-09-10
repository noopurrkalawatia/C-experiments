#include <iostream>

using namespace std;
class smartPtr
{
    public:
    int *ptr;

    explicit smartPtr(int *p = NULL)
    {
        cout << "I am here" << endl;
        cout << "contents of p are" << *p << endl;
        ptr = p;
        cout << "contents of ptr are" << *ptr << endl;
    }

    ~smartPtr()
    {
        cout << "I am deleting my pointer" << endl;
        delete(ptr);
    }

    int& operator *()
    {
        return *ptr;
    }

    int* operator ->()
    {
        return ptr;
    }
};

int main(void)
{
    int a = 10;
    int *p = &a;

    smartPtr p1(new int());
    cout << "assigning the value here" << endl;
    *p1 = a;

    cout << *p1 << endl;
    return 0;
}