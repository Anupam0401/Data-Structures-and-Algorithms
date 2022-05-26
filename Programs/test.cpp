

#include <iostream>

using namespace std;
#include<stdio.h>
#include<bits/stdc++.h>
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d",&n);
		scanf("%d",&k);
		int a[n];
		int d[k];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=0;i<k;i++)
		{
			scanf("%d",&d[i]);
		}
		int result[n];
		for(int i=0;i<n;i++){
			result[i]=0;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<k;j++){
				if(a[i]>=d[j]) result[i]++;
			}
		}
		/*for(int i=0;i<n;i++){
			printf("%d",result[i]);
		}
		printf("\n");*/
		for(int i=0;i<n;i++){
			int c=0;
			for(int j=0;j<n;j++){

				if(result[i]>=result[j]) c++;

				}
				if(c==n){
					printf("%d\n",i);
					break;}
			}
		}
		return 0;
	}
