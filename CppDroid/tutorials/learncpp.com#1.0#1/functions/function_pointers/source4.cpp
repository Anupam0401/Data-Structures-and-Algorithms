int foo()
{
}

int goo()
{
}

int main()
{
    int (*pFoo)() = foo; // pFoo points to function foo()
    pFoo = goo; // pFoo now points to function goo()
    return 0;
}