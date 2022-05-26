class A
{
public:
    virtual const char* GetName() { return "A"; }
};

class B: public A
{
public:
    virtual const char* GetName() { return "B"; }
};

class C: public B
{
public:
    virtual const char* GetName() { return "C"; }
};

class D: public C
{
public:
    virtual const char* GetName() { return "D"; }
};

int main()
{
    C cClass;
    A &rBase = cClass;
    cout << "rBase is a " << rBase.GetName() << endl;

    return 0;
}