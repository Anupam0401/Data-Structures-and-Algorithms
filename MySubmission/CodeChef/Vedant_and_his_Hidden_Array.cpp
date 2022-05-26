#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#define lli long long int
using namespace std;

// Given the bitwise AND of all elements of the array of size n, determine whether the total sum of the elements is odd, even or cannot be determined.

// Input Format
// n is the number of elements in the hidden array and a is the bitwise AND of all the elements in the hidden array.

// Output Format
// output Even if the sum of all elements in the hidden array is even, Odd if the sum of all elements in the hidden array is odd, or Impossible if the parity cannot be determined.
// Time complexity : O(n)
void solve(lli n, int a){
    if(n==1){
        if(a%2==0)
            cout<<"Even"<<endl;
        else
            cout<<"Odd"<<endl;
        return;
    }
    else{
        if(n&1 && a%2==0)   cout<<"Impossible"<<endl;
        else if(n&1 && a%2==1)   cout<<"Odd"<<endl;
        else if(!(n&1) && a%2==0)   cout<<"Impossible"<<endl;
        else if(!(n&1) && a%2==1)   cout<<"Even"<<endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        lli n,a;
        cin>>n>>a; 
        solve( n,  a);
    }
    return 0;
}