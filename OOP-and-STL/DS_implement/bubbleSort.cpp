#include<bits/stdc++.h>
using namespace std;

// implement bubble sort

// Approach of Bubble Sort:
// 1. Compare adjacent elements
// 2. Swap if the elements are not in the correct order
// 3. Repeat the process for the remaining elements

// time complexity: O(n^2)
// space complexity: O(1)

void bubbleSort(vector<int> &arr){
    for(int i=0; i<arr.size()-1; i++){
        for(int j=0; j<arr.size()-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)    cin>>arr[i];
    bubbleSort(arr);
    for(int i=0;i<n;i++)    cout<<arr[i]<<" ";
    return 0;
}