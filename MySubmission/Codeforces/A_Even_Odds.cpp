#include <bits/stdc++.h>
using namespace std;
#define lli long long int

lli getNum(lli n, lli k)
{
    if (n % 2 == 0)
    {
        if (k <= n / 2)
        {
            return 2 * k - 1;
        }
        else
        {
            k -= n / 2;
            return 2 * k;
        }
    }
    else{
        if (k <= n / 2 +1)
        {
            return 2 * k - 1;
        }
        else
        {
            k -= (n / 2 + 1);
            return 2 * k;
        }
    }
    return 0;
}
int main()
{
    lli n, k;
    cin >> n >> k;
    cout<<getNum(n,k)<<endl;
    return 0;
}