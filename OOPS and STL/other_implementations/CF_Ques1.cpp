#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int c=n;
        long int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        long int f=0;

        while(f!=a[n-1])
        {
            sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            if(a[i]!=0) {
                f=a[i];
                break;
            }
        }
         for(int i=0;i<n-1;i++)
         {
             if(a[i]!=a[i+1]&&a[i]!=0)
             {
                 a[i]=a[i]+a[i+1];
                 a[i+1]=0;
                 i++;
                 c--;
             }
         }
        }
        cout<<c<<endl;
    }
    return 0;
}
