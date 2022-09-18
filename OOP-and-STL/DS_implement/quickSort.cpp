#include<bits/stdc++.h>
using namespace std;

// Approach of Quick Sort:
// 1. Pick a pivot element
// 2. Partition the array around the pivot element
// 3. Recursively sort the left and right subarrays

void quickSort(vector<int> &arr, int start, int end){
    if(start<end){
        int pivot = arr[end];
        int i = start-1;
        for(int j=start; j<end; j++){
            if(arr[j]<pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[end]);
        quickSort(arr,start,i);
        quickSort(arr,i+2,end);
    }
}

// time complexity: O(nlogn)
// space complexity: O(logn)

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)    cin>>arr[i];
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++)    cout<<arr[i]<<" ";
    return 0;
}