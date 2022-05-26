class Base
{
public:
    const char* SayHi() { return "Hi"; } // a normal non-virtual function    

    virtual const char* GetName() { return "Base"; } // a normal virtual function

    virtual int GetValue() = 0; // a pure virtual function
};