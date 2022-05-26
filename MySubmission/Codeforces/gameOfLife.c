#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
    while(t--) {
        long long int n,m,i,j;
        scanf("%lld", &n);
        scanf("%lld", &m);
        int a[n],b[n],flag=0,goon=1;
        char s[n];
        scanf("%s",s);
        for(i=0; i<n; i++){
            a[i]=((int)s[i])-48;
            if(a[i]==0) flag=1;
            b[i]=a[i];
        }
        if(flag==1){
            for(j=1;j<=m;j++){
                goon=0;
                if(a[0]==0 && a[1]==1) b[0]=1;
                if(a[n-1]==0 && a[n-2]==1) b[n-1]=1;
                for(i=1; i<n-1; i++){
                    if(a[i]==0 && a[i-1]+a[i+1]==1){
                        b[i]=1;
                        goon=1;
                    }
                }
                for(i=0; i<n; i++){
                    a[i]=b[i];
                }
                // for(i=0; i<n; i++){
                //         cout<<a[i]<<" ";
                //     }
                //     cout<<"\n";
                if(goon==0) break;
            }
        }
        for(i=0; i<n; i++){
            s[i]=(char)(a[i]+48);
        }
        printf("%s\n", s);
    }
	return 0;
}