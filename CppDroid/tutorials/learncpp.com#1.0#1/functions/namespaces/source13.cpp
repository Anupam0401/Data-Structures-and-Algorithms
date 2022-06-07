int main(void)
{
    using namespace std;
    using namespace Foo; // look in namespace Foo
    using namespace Goo; // look in namespace Goo
    cout << DoSomething(4, 3) << endl;
    return 0;
}