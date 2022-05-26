#include<stdio.h>
int main() {
	int t;
	scanf("%d", &t);
    while(t--) {
        int xa,xb,Xa,Xb;
        scanf("%d %d %d %d", &xa,&xb,&Xa,&Xb);
        printf("%d\n",(Xa/xa+Xb/xb));
    }
	return 0;
}