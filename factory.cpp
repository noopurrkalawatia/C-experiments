
#include <iostream>

using namespace std;

enum Vtype
{
    TV_Two, TV_Three, TV_Four, TV_five
};

class shape
{
    public:
    virtual void printType() = 0;
    static shape* create(Vtype type1);
};

class square:public shape
{
    public:
    void printType()
    {
        cout << "I am a square" << endl;
    }
};

class triangle:public square
{
    public:
    void printType()
    {
        cout << "I am a triangle" << endl;
    }
};

class rectangle:public shape
{
    public:
    void printType()
    {
        cout << "I am a rectangle" << endl;
    }
};

shape* shape::create(Vtype type1)
{
    if(type1 == TV_Two)
    {
        return new square();
    }
    else if(type1 == TV_Three)
    {
        return new triangle();
    }
    else if(type1 == TV_Four)
    {
        return new rectangle();
    }
    else
    {
        return NULL;
    }
}

class client
{
    public:
    shape *shapePtr;
    client(Vtype type1)
    {
        shapePtr = shape::create(type1);
    }
    
    ~client()
    {
        delete[] shapePtr;
        shapePtr = NULL;
    }
    
    shape* getshape()
    {
        return shapePtr;
    }
};

int main()
{
    client *C1 = new client(TV_Three);
    shape *s = C1->getshape();
    s->printType();
    return 0;
}
