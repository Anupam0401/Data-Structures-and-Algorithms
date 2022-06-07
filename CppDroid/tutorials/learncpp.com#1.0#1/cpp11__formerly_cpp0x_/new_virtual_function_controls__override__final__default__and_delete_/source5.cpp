class Foo
{
    Foo(int x); // Custom constructor
    Foo() = default; // The compiler will now provide a default constructor for class Foo as well
};