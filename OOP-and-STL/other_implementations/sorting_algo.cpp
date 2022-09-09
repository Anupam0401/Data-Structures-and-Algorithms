#include<bits/stdc++.h>
using namespace std;

// void merge(vector<int>& arr, int l, int mid, int r){
//     int n1 = mid - l + 1;
//     int n2 = r - mid;
//     vector<int> L(n1), R(n2);
//     for(int i = 0; i < n1; i++)
//         L[i] = arr[l + i];
//     for(int i = 0; i < n2; i++)
//         R[i] = arr[mid + 1 + i];
//     int i = 0, j = 0, k = l;
//     while(i < n1 && j < n2){
//         if(L[i] <= R[j]){
//             arr[k] = L[i];
//             i++;
//         }
//         else{
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }
//     while(i < n1){
//         arr[k] = L[i];
//         i++;
//         k++;
//     }
//     while(j < n2){
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }

void merge(vector<int>& a, int l, int mid, int r){
    int n = r-l+1;
    vector<int> b(n);
    int i=l,j=mid+1,k=l;
    while(i<=mid and j<=r){
        if(a[i]<a[j]){
            b[k] = a[i++];
        }
        else{
            b[k] = a[j++];
        }
        k++;
    }
    while(j<=r) b[k++] = a[j++];
    while(i<=mid)   b[k++] = a[i++];
    for(int i=l;i<=r;i++)    a[i] = b[i];
}

void mergeSort(vector<int>& arr, int l, int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}