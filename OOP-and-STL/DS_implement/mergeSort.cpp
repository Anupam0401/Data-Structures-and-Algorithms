#include<bits/stdc++.h>
using namespace std;


void merge(vector<int> &arr, int left, int mid, int right){
    // perform merge inplace
    int i = left, j = mid+1, k = 0;
    vector<int> temp(right-left+1);
    while(i<=mid && j<=right){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=right){
        temp[k++] = arr[j++];
    }
    for(int i=left; i<=right; i++){
        arr[i] = temp[i-left];
    }
}

// time complexity: O(nlogn)
// space complexity: O(n)
void mergeSort(vector<int> &arr, int start, int end){
    if(start<end){
        int mid = start+(end-start)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}

void printArr(vector<int> &arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    printArr(arr);
    return 0;
}