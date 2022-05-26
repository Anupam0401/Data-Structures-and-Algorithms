class Foo
{
    void Foo(long long); // Can create Foo() with a long long
    template<typename T> void Foo(T) = delete; // But can't create it with anything else
};