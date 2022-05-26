#include <foo.h>
#include <goo.h>
#include <iostream>

int main()
{
    using namespace std;
    cout << DoSomething(4, 3); // which DoSomething will we get?
    return 0;
}