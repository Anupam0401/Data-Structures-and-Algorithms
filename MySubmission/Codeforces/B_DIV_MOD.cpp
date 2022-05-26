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
        lli l, r, a;
        cin >> l >> r >> a;
        lli ans = r / a + (r % a);
        if (a <= r)
        {
            for (lli i = r; i >= l; i--)
            {
                ans = max(ans, (i / a + (i % a)));
                if ((i + 1) % a == 0)
                {
                    // ans=max(ans,(i/a + (i%a)));
                    break;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}