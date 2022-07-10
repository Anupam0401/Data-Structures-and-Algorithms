// Let s be a string of lowercase Latin letters. Its price is the sum of the indices of letters (an integer between 1 and 26) that are included in it. For example, the price of the string abca is 1+2+3+1=7.

// The string w and the integer p are given. Remove the minimal number of letters from w so that its price becomes less than or equal to p and print the resulting string. Note that the resulting string may be empty. You can delete arbitrary letters, they do not have to go in a row. If the price of a given string w is less than or equal to p, then nothing needs to be deleted and w must be output.

// Note that when you delete a letter from w, the order of the remaining letters is preserved. For example, if you delete the letter e from the string test, you get tst.

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
        string s;
        cin>>s;
        lli n = s.length();
        lli p;
        cin>>p;
        unordered_map<char,int> mp;
        // initialize the map with -1
        for(int i=0;i<26;i++){
            mp[(char)(i+97)]=-1;
        }
        lli total_price=0;
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
            total_price+=s[i]-'a'+1;
        }
        if(total_price<=p){
            cout<<s<<endl;
            continue;
        }
        string ans = "";
        lli ans_price = 0;
        for(int i=0;i<n;i++){
            if(mp[s[i]]!=-1){
                ans+=s[i];
                ans_price+=s[i]-'a'+1;
                mp[s[i]]=-1;
                if(ans_price>p){
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
