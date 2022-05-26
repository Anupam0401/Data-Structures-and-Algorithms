#include<stdio.h>
#include<stdlib.h>
long long int cmpfunc (const void * a, const void * b) {
   return ( *(long long int*)a - *(long long int*)b );
}
int main() {
	int t;
	scanf("%d", &t);
    while(t--) {
        long int n,k;
        scanf("%ld", &n);
        scanf("%ld", &k);
        long long int a[n],i;
        for(i= 0;i<n;i++){
            scanf("%lld", &a[i]);
        }
        long long int sum1=0,sum2=0;
        qsort(a, n, sizeof(long long int), cmpfunc);
        for(i=n-1;i>=0 && k>0 ; i--){
            if(i%2==0) {
                sum1+=a[i];
                //cout<<"sum1-"<<sum1<<" "<<a[i]<<endl;
            }
            else {
                sum2+=a[i];
                k--;
                // cout<<"sum2-"<<sum2<<" "<<a[i]<<endl;
            }
        }
        if(k<=0) sum2+=a[0];
        if(sum1>sum2){
            printf("%lld\n", sum1);
        }
        else printf("%lld\n", sum2);
    }
	return 0;
}