#include <stdio.h>
long long int max(long long int x[],int n)
{
    long long int m;
    m=x[0];
    for(int i=0;i<n;i++)
    {
        if(x[i]>m)
        m=x[i];
    }
    return m;
}
 int main()
 {
     int l;
     scanf("%d",&l);
     for(int i=1;i<=l;i++)
     {
         int n;
         scanf("%d",&n);

         long long int a[n],b[n];
         for(int j=0;j<n;j++)
         {
             scanf("%lld",&a[j]);
         }
         for(int j=0;j<n;j++)
         {
             scanf("%lld",&b[j]);
         }
         long long int ma=max(a,n);
         long long int mb=max(b,n);
         if(ma!=mb)
         printf("YES\n");
         else
         printf("NO\n");
     }
     return 0;
 }
