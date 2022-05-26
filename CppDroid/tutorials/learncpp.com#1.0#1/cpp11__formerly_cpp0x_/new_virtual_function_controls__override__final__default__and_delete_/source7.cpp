class Foo
{
    void Foo(long long); // Can create Foo() with a long long
    void Foo(long) = delete; // But can't create it with anything smaller
};