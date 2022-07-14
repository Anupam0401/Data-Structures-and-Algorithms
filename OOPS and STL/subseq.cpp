#include<bits/stdc++.h>
using namespace std;

void printSubseqWithSum(int index,vector<int> &ds,int s, int sum, int arr[],int n){
    if(index==n){
        if(s==sum){
            for(auto it:ds){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }
    ds.push_back(arr[index]);
    s+=arr[index];
    printSubseqWithSum(index+1,ds,s,sum,arr,n);
    ds.pop_back();
    s-=arr[index];
    printSubseqWithSum(index+1,ds,s,sum,arr,n);
}

void printAllSubseqs(int index, vector<int> &ds, int arr[], int n){
    if(index==n){
        for(auto it:ds) cout<<it<<" ";
        cout<<endl;
        return;
    }
    ds.push_back(arr[index]);
    printAllSubseqs(index+1,ds,arr,n);
    ds.pop_back();
    printAllSubseqs(index+1,ds,arr,n);
}

bool printOneSubseqWithSum(int index, vector<int> &ds, int arr[], int n, int s, int sum){
    if(index==n){
        if(s==sum){
            for(auto it:ds) cout<<it<<" ";
            cout<<endl;
            return true;
        }
        else return false;
    }
    ds.push_back(arr[index]);
    s+=arr[index];
    if(printOneSubseqWithSum(index+1,ds,arr,n,s,sum)==true) return true;
    s-=arr[index];
    ds.pop_back();
    if(printOneSubseqWithSum(index+1,ds,arr,n,s,sum)==true) return true;
    return false;
}

int countSubseqWithSum(int index, int s, int arr[], int sum, int n){
    if(index==n){
        if(s==sum)  return 1;
        else return 0;
    }
    s+=arr[index];
    int l = countSubseqWithSum(index+1,s,arr,sum,n);
    s-=arr[index];
    int r = countSubseqWithSum(index+1,s,arr,sum,n);
    return l+r;
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 20;
    vector<int> ds;
    // printSubseqWithSum(0,ds,0,sum,arr,n);
    // printAllSubseqs(0,ds,arr,n);
    cout<<printOneSubseqWithSum(0,ds,arr,n,0,sum)<<endl;
    // cout<<countSubseqWithSum(0,0,arr,sum,n)<<endl;
    return 0;
}