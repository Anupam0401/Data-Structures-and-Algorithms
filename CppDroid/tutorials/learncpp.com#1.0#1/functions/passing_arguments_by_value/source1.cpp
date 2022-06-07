void foo(int y)
{
    using namespace std;
    cout << "y = " << y << endl;
}

int main()
{
    foo(5); // first call

    int x = 6;
    foo(x); // second call
    foo(x+1); // third call

    return 0;
}