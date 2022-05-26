void foo(int y)
{
    using namespace std;
    cout << "y = " << y << endl;

    y = 6;

    cout << "y = " << y << endl;
} // y is destroyed here

int main()
{
    using namespace std;
    int x = 5;
    cout << "x = " << x << endl;

    foo(x);

    cout << "x = " << x << endl;
    return 0;
}