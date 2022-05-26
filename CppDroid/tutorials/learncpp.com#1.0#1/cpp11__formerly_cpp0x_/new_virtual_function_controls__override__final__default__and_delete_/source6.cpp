class Foo
{
    Foo& operator=(const Foo&) = delete; // disallow use of assignment operator
    Foo(const Foo&) = delete; // disallow copy construction
};