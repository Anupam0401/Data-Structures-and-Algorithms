#include<bits/stdc++.h>
using namespace std;

// Approach of Insertion Sort:
// 1. Insert the element at the correct position in the sorted array
// 2. Repeat the process for the remaining elements

void insertionSort(vector<int> &arr){
    for(int i=1; i<arr.size(); i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// time complexity: O(n^2)
// space complexity: O(1)

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)    cin>>arr[i];
    insertionSort(arr);
    for(int i=0;i<n;i++)    cout<<arr[i]<<" ";
    return 0;
}