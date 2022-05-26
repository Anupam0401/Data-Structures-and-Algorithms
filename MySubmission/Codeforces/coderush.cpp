#include <bits/stdc++.h>
#include <algorithm>
#define lli long long int

const long long int MOD = 1000000007;
using namespace std;

// You are God and you represent poverty of N people as an array of N integers. Event is breaking this array into a contagious subarray. For this event there will be N * (N+1) / 2 contagious subarrays possible each of which goes to a multiverse, so every multiverse has a unique subarray representing a population. Lets define unfairness of a subarray as difference between maximum integer and minimum integer. You need to find sum of unfairness of all multiverse.

// Input Format
// First line contains an integer N, represnting number of integers in origianl array. The second line will contain N integers a1, a2,...,aN representing poverty of every person seperated by space

// function for sum of max min difference
void maxMin (vector<lli>arr, lli n)
{
    // sort all numbers
    sort(arr.begin(), arr.end());
    
    // iterate over array and with help of
    // horner's rule calc max_sum and min_sum
    long long int min_sum = 0, max_sum = 0;
    for (lli i = 0; i < n; i++)
    {
        max_sum = 2 * max_sum + arr[n-1-i];
        max_sum %= MOD;
        min_sum = 2 * min_sum + arr[i];
        min_sum %= MOD;
    }

    cout<<(max_sum - min_sum + MOD) % MOD<<endl;
}

void unfairnessAcrossUniverse(){
    lli n;
    cin>>n;
    vector<lli> a(n,0);
    for(lli i=0;i<n;i++){
        cin>>a[i];
    }
    maxMin(a,n);
    // lli sum=0;
    // for(lli i=0;i<n;i++){
    //     lli max=a[i];
    //     lli min=a[i];
    //     for(lli j=i+1;j<n;j++){
    //         max=max>a[j]?max:a[j];
    //         min=min<a[j]?min:a[j];
    //         sum+=max-min;
    //     }
    // }
    // cout<<sum<<endl;
}





// // Driver Code
// int main()
// {
//     int arr[] = {1, 2, 3, 4};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << maxMin(arr,n);
//     return 0;
// }


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unfairnessAcrossUniverse();
    return 0;
}