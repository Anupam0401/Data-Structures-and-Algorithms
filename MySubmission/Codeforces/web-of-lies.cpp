#include <bits/stdc++.h>
using namespace std;
#define M 200005
int cnt[M];
int ans;
int main()
{
    int i, j, n, m, q, a, b, opt;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= m; i++)
    {
        scanf("%d %d", &a, &b);
        if (a > b)
            cnt[b]++;
        else
            cnt[a]++;
    }
    for (i = 1; i <= n; i++)
    {
        if (cnt[i] == 0)
            ans++;
    }
    scanf("%d", &q);
    for (i = 1; i <= q; i++)
    {
        scanf("%d", &opt);
        if (opt == 1)
        {
            scanf("%d %d", &a, &b);
            if (a > b)
                swap(a, b);
            if (cnt[a] == 0)
                ans--;
            cnt[a]++;
        }
        if (opt == 2)
        {
            scanf("%d %d", &a, &b);
            if (a > b)
                swap(a, b);
            if (cnt[a] == 1)
                ans++;
            cnt[a]--;
        }
        if (opt == 3)
        {
            printf("%d\n", ans);
        }
    }
    return 0;
}