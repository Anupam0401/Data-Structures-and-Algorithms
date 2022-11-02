#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        sum+=nums[i];
    }
    sort(nums.begin(),nums.end(),greater<int>());
    sum = sum/2;
    int t = 0;
    int i;
    for(i=0;i<n;i++){
        t+=nums[i];
        if(t>sum)   break;
    }
    cout<<i+1<<endl;
}