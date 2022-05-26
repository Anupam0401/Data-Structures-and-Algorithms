void foo(const int &x)
{
    x = 6;  // x is a const reference and can not be changed!
}