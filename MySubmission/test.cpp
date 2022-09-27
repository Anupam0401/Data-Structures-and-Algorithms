// //table name: Loan
// // PK- id
// // user_id: attribute


// //
// userid|id
// // 12 - 1
// // 12 - 2 
// // 13 - 3 
// // 14 - 4




// (SELECT DISTINCT Loan.userid from Loan)

// SELECT * FROM Loan
// GROUP BY userid
// ORDER BY id DESC;

// //SFML


// //a,b

// a=a+b 
// b=a-b
// a=a-b

// [1,0,0,0,1,0,1,0]
// Approach:
// 1. Replace the value 0 by -1
// 2. Maintain a hash map to store the points where we find the sum value 0

#include<bits/stdc++.h>
using namespace std;


int getMaxLength(vector<int> &arr){
    int n = arr.size();
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        if(arr[i]==0)   arr[i]=-1;
    }
    int sum = 0;
    int maxL = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0){
            maxL = i+1;
        }
        if(mp.find(sum)!=mp.end()){ //mp[i] = ind at which we encountered the sum = 0, i.e., till then the number of values of 0==1
            if(maxL<i-mp[sum]){ //i-mp[sum]: new_length where the condition is satisfied
                maxL = i-mp[sum];
            } 
        }
        else{
            mp[sum]=i;
        }
    }
    return maxL;
}

int main(){
    vector<int> arr={1,0,0,0,1,0,1,0};
    cout<<getMaxLength(arr);
    return 0;
}





