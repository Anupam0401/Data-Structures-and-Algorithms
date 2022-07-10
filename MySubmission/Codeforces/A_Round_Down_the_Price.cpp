#include <bits/stdc++.h>
#include <algorithm>
#define lli long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        lli m;
        cin >> m;
        // count the number of digits in m
        int n = 0;
        int temp = m;
        while (temp > 0)
        {
            temp /= 10;
            n++;
        }
        --n;
        //  subtract 10^n from m
        lli ans = m - pow(10, n);
        cout << ans << endl;
    }

    return 0;
}
