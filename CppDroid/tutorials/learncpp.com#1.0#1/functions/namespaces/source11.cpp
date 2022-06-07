int main(void)
{
    using namespace std;
    using namespace Foo; // look in namespace Foo
    cout << DoSomething(4, 3) << endl;
    return 0;
}