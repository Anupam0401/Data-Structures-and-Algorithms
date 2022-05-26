#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
    while(t--) {
        long long int n;
        scanf("%lld", &n);
        int a[n];
        for(long long int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        printf("%lld\n",(n/2)*6);
        for(long long int i=0; i<n-1; i+=2){
            printf("1 %lld %lld\n",(i+1),(i+2));
            printf("2 %lld %lld\n",(i+1),(i+2));
            printf("1 %lld %lld\n",(i+1),(i+2));
            printf("1 %lld %lld\n",(i+1),(i+2));
            printf("2 %lld %lld\n",(i+1),(i+2));
            printf("1 %lld %lld\n",(i+1),(i+2));
        }
    }
	return 0;
}