#include <iostream>
int ReadNumber()
{
    using namespace std;
    cout << "Enter a number: ";
    int x;
    cin >> x;
    return x;
}

void WriteAnswer(int x)
{
    using namespace std;
    cout << "The answer is " << x << endl;
}

int main()
{
    int x = ReadNumber();
    int y = ReadNumber();
    WriteAnswer(x+y);
    return 0;
}