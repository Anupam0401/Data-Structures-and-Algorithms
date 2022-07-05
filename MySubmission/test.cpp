

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // The king of Geekland has ordered to build a Colosseum for fighting.
    // For the inauguration fight, he asks his minister to bring in 3*N fighters.
    // Each fighter is denoted by a roll number from 1 to 3*N. An array A of length
    // 3*N is given such that ith element denotes the strength of the fighter with
    // in roll number.
    // From these fighters, N fighters will be removed. The remaining 2*N will be
    // divided into two groups based on their roll numbers. N fighters with the
    // smallest roll numbers will be put in group1 and the N fighters with the largest
    // roll numbers will be group2. The two groups will then fight each other.
    // Let the total sum of the strength of group1 be S and the total sum of the
    // strength of group2 be S2. The fight will be interesting if S1- S2 is as large as
    // possible. Find the maximum value of S1 - S2.
    class Solution
    {
    public:
        long long colosseum(int n, vector<int> a)
        {
            vector<int> dummy(3*n,0);
            for(int i=0;i<3*n;i++)
                dummy[i]=a[i];
            // partition the array into two groups of size 3*n/2
            int l=0,r=3*n-1;
            int mid=3*n/2;
            while(l<r){
                if(dummy[l]>dummy[mid]){
                    swap(dummy[l],dummy[mid]);
                    l++;
                    mid++;
                }
                else if(dummy[l]<dummy[mid]){
                    swap(dummy[l],dummy[r]);
                    r--;
                }
                else{
                    l++;
                    mid++;
                }
            }
            // now, dummy[l] is the median
            long long sum1=0,sum2=0;
            // take sum1 and sum2 of n elements from each of the two groups
            for(int i=0;i<n;i++){
                sum1+=dummy[i];
                sum2+=dummy[i+n];
            }
            return sum1-sum2;
        }
    };
}