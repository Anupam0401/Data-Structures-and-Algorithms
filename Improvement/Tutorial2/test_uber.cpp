#include<bits/stdc++.h>
#include<vector>
using namespace std;
int getPowerCouple2021(int friends_nodes, int friends_edges, vector<int> friends_from, vector<int> friends_to, vector<int> friends_weight) {
    int value[friends_nodes][friends_nodes]={0};
    int c=0;
    for(auto i=friends_weight.begin(),j=friends_from.begin(),k=friends_to.begin(); i!=friends_weight.end();++i,++j,++k) {
        for(int p=0;p<friends_nodes;p++){
            if(value[*j-1][p]==0||value[*j-1][p]==*i)
                value[*j-1][p]=*i;
        }
        for(int p=0;p<friends_nodes;p++){
            if(value[*k-1][p]==0||value[*k-1][p]==*i)
                value[*k-1][p]=*i;        
        }
    }
    int p=0,q=0,max=-1,ans=0;
    for(p=0;p<friends_nodes-1;p++){
    	for(int r=p+1;r<friends_nodes;r++){
            q=0;
            int c = 0;
            while(value[p][q]!=0)
            {
                int s=0;
                while(value[r][s]!=0)
                {
                    if(value[p][q]==value[r][s])
                        c++;
                    s++;
                }
                q++;
            }
            if(c>max){
                max=c;
                ans=(p+1)*(r+1);
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> vec={1,1,2,2};
    vector<int> vec1={3,3,4,4};
    vector<int> vec2={1,2,1,2};
    cout<<getPowerCouple2021(4, 4, vec, vec1, vec2)<<endl;
}