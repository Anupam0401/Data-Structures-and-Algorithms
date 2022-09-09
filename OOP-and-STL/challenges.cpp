#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    int flag = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
void primeBetweenTwoNumbers(int a, int b)
{
    int i, j, flag = 0;
    for (i = a; i <= b; i++)
    {
        if (isPrime(i))
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    primeBetweenTwoNumbers(a, b);
    return 0;
}