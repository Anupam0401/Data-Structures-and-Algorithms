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

// passwords must contain:

// At least 7 characters.
// At least one uppercase English alphabet letter.
// At least one lowercase English alphabet letter.
// At least one digit.
// At least one special character. There are four special characters: #, @, *, and &.

// Can you help Charles to find the shortest possible new password that satisfies his company's requirements?

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
        cin>>n;
        string oldPassword;
        cin>>oldPassword;
        //check if the old password is valid
        bool valid = true;
        if(oldPassword.length() < 7)
            valid = false;
        bool hasUpper = false;
        bool hasLower = false;
        bool hasDigit = false;
        bool hasSpecial = false;
        for(int i = 0; i < oldPassword.length(); i++)
        {
            if(isupper(oldPassword[i]))
                hasUpper = true;
            if(islower(oldPassword[i]))
                hasLower = true;
            if(isdigit(oldPassword[i]))
                hasDigit = true;
            if(oldPassword[i] == '#' || oldPassword[i] == '@' || oldPassword[i] == '*' || oldPassword[i] == '&')
                hasSpecial = true;
        }
        if(!hasUpper || !hasLower || !hasDigit || !hasSpecial)
            valid = false;
        // if the old password is invalid, make it valid by appending minimum characters
        if(!valid)
        {
            int noUpper = 0;
            int noLower = 0;
            int noDigit = 0;
            int noSpecial = 0;
            for(int i = 0; i < oldPassword.length(); i++)
            {
                if(isupper(oldPassword[i]))
                    noUpper++;
                if(islower(oldPassword[i]))
                    noLower++;
                if(isdigit(oldPassword[i]))
                    noDigit++;
                if(oldPassword[i] == '#' || oldPassword[i] == '@' || oldPassword[i] == '*' || oldPassword[i] == '&')
                    noSpecial++;
            }
            if(noSpecial < 1)
                oldPassword += '#';
            if(noDigit < 1)
                oldPassword += '0';
            if(noUpper < 1)
                oldPassword += 'A';
            if(noLower < 1)
                oldPassword += 'a';
            if(oldPassword.length() < 7)
            {
                int diff = 7 - oldPassword.length();
                for(int i = 0; i < diff; i++)
                {
                    oldPassword += '0';
                }
            }
        }
        // now oldPassword is valid
        cout << "Case #" << p << ": " << oldPassword << "\n";
    }
    return 0;
}