#include <iostream>
int add(int x, int y);

int main()
{
    using namespace std;
    cout << "3 + 4 + 5 = " << add(3, 4, 5) << endl;
    return 0;
}

int add(int x, int y, int z)
{
    return x + y + z;
}