#include<stdio.h>
int main() {
	int t;
	scanf("%d", &t);
    while(t--) {
        long int n;
        scanf("%ld", &n);
        long int x=n/2+1;
        printf("%ld\n", x);
    }
	return 0;
}