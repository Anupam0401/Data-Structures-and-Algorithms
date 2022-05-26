#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long int t;
    cin >> t;
    while (t--)
    {
        long int D, d, p, q;
        cin >> D >> d >> p >> q;
        long int sum = 0;
        long int n = D / d;
        if (D % d != 0)
        {
            sum += (n * (2 * p * d + (n - 1) * q * d)) / 2;
            sum += (D - n * d) * (p + n * q);
        }
        else
        {
            sum += (n * (2 * p * d + (n - 1) * q * d)) / 2;
        }
        cout << sum << endl;
    }
    return 0;
}