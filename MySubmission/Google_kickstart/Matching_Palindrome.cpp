#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// You are given a palindrome string P of length N consisting of only lowercase letters of the English alphabet. Find the shortest non-empty palindrome string Q such that P concatenated with Q forms a palindrome. Formally, the string PQ forms a palindrome.

bool checkPalindrome(string s)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    for(int p=1; p<=n; p++)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        string res="";
        for(int i=0;i<n;i++){
            res+=s[i];
            if(checkPalindrome(s+res))
                break;
        }
        cout<<"Case #"<<p<<": "<<res<<endl;
    }
}