class Foo
{
public:
    Foo()
    {
        // code to do A
    }

    Foo(int nValue): Foo() // use Foo() default constructor to do A
    {
        // code to do B
    }
};