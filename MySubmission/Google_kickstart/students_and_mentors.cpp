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

lli gcd(lli a, lli b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int diff(int a, int b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}

lli isAP(lli a, int b)
{
    return ((a + b) % 2 == 0) ? (a + b) / 2 : 1000000006;
}

// A group of N students prepares together for upcoming programming competitions such as Kick Start and Code Jam by Google. To help each other prepare, it was decided that each student will pick a mentor among other students. A mentor will help their mentee to solve problems, learn algorithms, track their progress, and will generally support them throughout preparation.

// Each student will have exactly one mentor among all other students, and a person can be a mentor to multiple people. For every student i we know their rating Ri which approximates how good that student is at programming competitions. Because it is believed that a mentor should not be much stronger than their mentee, a student j can be a mentor of student i only if Rj≤2×Ri. Note that a mentor can even have a rating that is lower or equal to their mentee's rating.

// Unsurprisingly, each student wants to have the strongest possible mentor. For each student, can you help to figure out what is the highest possible rating of a mentor they can pick?

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int p = 1; p <= t; p++)
    {
        int n;
        cin >> n;
        vector<int> ratings(n);
        for(int i=0;i<n;i++)    cin>>ratings[i];
        vector<pair<int,int>> sorted_ratings(n);
        for(int i=0;i<n;i++)    sorted_ratings[i]={ratings[i],i};
        sort(sorted_ratings.begin(), sorted_ratings.end(), greater<pair<int,int>>());
        int highest = ratings[0];
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++)
        {
            // find the first element whose rating is less than or equal to 2*ratings[i] and that element is not i itself
            for(int j=0;j<n;j++)
            {
                if(sorted_ratings[j].first<=2*ratings[i] && sorted_ratings[j].second!=i)
                {
                    ans[i]=sorted_ratings[j].first;
                    break;
                }

            }
        }
        cout << "Case #" << p << ": ";
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}