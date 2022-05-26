class A
{
public:
    A()
    {
        cout << "A" << endl;
    }
};

class B: public A
{
public:
    B()
    {
        cout << "B" << endl;
    }
};

class C: public B
{
public:
    C()
    {
        cout << "C" << endl;
    }
};

class D: public C
{
public:
    D()
    {
        cout << "D" << endl;
    }
};