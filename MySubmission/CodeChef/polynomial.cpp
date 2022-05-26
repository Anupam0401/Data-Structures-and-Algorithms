#include <bits/stdc++.h>
#include <algorithm>
#define mod 1000000007
#define lli long long int
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
using namespace std;

lli add(lli a, lli b)
{
    a += b;
    return (a >= mod ? a - mod : a);
}

lli sub(lli a, lli b)
{
    a -= b;
    return (a < 0 ? a + mod : a);
}

lli mul(lli a, lli b)
{
    a *= b;
    return (a >= mod ? a % mod : a);
}

lli power(lli a, lli b)
{
    lli result = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            result = mul(result, a);
        b >>= 1;
        a = mul(a, a);
    }
    return result;
}

long int min_distance_left(long int *a, long int dest)
{
    dest--;
    long int x = dest;
    while (x >= 0)
    {
        if (*(a + x) == 1)
            return (dest - x);
        x--;
    }
    return -1;
}

long int min_distance_right(long int *a, long int dest, long int n)
{
    dest--;
    long int x = dest;
    while (x < n)
    {
        if (*(a + x) == 2)
            return (x - dest);
        x++;
    }
    return -1;
}
// lli binarySearch(lli arr[], lli l, lli r, lli x)
// {
//     if (r >= l)
//     {
//         lli mid = l + (r - l) / 2;

//         // If the element is present at the middle
//         // itself
//         if (arr[mid] == x)
//             return mid;

//         // If element is smaller than mid, then
//         // it can only be present in left subarray
//         if (arr[mid] > x)
//             return binarySearch(arr, l, mid - 1, x);

//         // Else the element can only be present
//         // in right subarray
//         return binarySearch(arr, mid + 1, r, x);
//     }

//     // We reach here when element is not
//     // present in array
//     return -1;
// }

lli leastgreater(lli a[], lli low, lli high, lli key)
{
    lli ans = -1;

    while (low <= high)
    {
        lli mid = low + (high - low + 1) / 2;
        lli midVal = a[mid];

        if (midVal < key)
        {

            // if mid is less than key, all elements
            // in range [low, mid - 1] are <= key
            // then we search in right side of mid
            // so we now search in [mid + 1, high]
            low = mid + 1;
        }
        else if (midVal > key)
        {

            // if mid is greater than key, all elements
            // in range [mid + 1, high] are >= key
            // we note down the last found index, then
            // we search in left side of mid
            // so we now search in [low, mid - 1]
            ans = mid;
            high = mid - 1;
        }
        else if (midVal == key)
        {

            // if mid is equal to key, all elements in
            // range [low, mid] are <= key
            // so we now search in [mid + 1, high]
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, q, i, j;
    cin >> n >> q;
    lli a[n], x[q], ans[q], t;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < q; i++)
    {
        cin >> x[i];
    }
    sort(a, a + n);
    if (n % 2 == 0)
    {
        for (i = 0; i < q; i++)
        {
            if (x[i] < a[0] || x[i] > a[n - 1])
                ans[i] = 1;
            else if (x[i] == a[n - 1])
                ans[i] = 0;
            else
            {
                // for (j = 0; j < n - 1; j++)
                // {
                //     if (x[i] == a[j])
                //     {
                //         ans[i] = 0;
                //         break;
                //     }
                //     else if (x[i] > a[j] && x[i] < a[j + 1])
                //     {
                //         if (j % 2 == 0)
                //             ans[i] = -1;
                //         else
                //             ans[i] = 1;
                //         break;
                //     }
                // }
                t = leastgreater(a, 0, n - 1, x[i]);
                t--;
                //cout << t << endl;
                if (x[i] == a[t] && t != 0)
                {
                    ans[i] = 0;
                }
                else
                {
                    if (t % 2 == 0)
                        ans[i] = -1;
                    else
                        ans[i] = 1;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < q; i++)
        {
            if (x[i] < a[0])
                ans[i] = -1;
            else if (x[i] > a[n - 1])
                ans[i] = 1;
            else if (x[i] == a[n - 1])
                ans[i] = 0;
            else
            {
                // for (j = 0; j < n - 1; j++)
                // {
                //     if (x[i] == a[j])
                //     {
                //         ans[i] = 0;
                //         break;
                //     }
                //     else if (x[i] > a[j] && x[i] < a[j + 1])
                //     {
                //         if (j % 2 == 0)
                //             ans[i] = 1;
                //         else
                //             ans[i] = -1;
                //         break;
                //     }
                // }
                t = leastgreater(a, 0, n - 1, x[i]);
                t--;
                if (x[i] == a[t] && t != 0)
                {
                    ans[i] = 0;
                }
                else
                {
                    if (t % 2 == 0)
                        ans[i] = 1;
                    else
                        ans[i] = -1;
                }
            }
        }
    }
    for (i = 0; i < q; i++)
    {
        if (ans[i] == 0)
            cout << ans[i] << endl;
        else if (ans[i] == 1)
            cout << "POSITIVE" << endl;
        else
            cout << "NEGATIVE" << endl;
    }
    return 0;
}