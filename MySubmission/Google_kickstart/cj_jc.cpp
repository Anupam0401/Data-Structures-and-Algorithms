#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int p=1; p<=n; p++)
    {
        int x,y;
        char s[1000];
        cin>>x>>y;
        scanf("%s",s);
        int i=0,sum=0;
        while(s[i+1]!='\0')
        {
            if(s[i]=='C'&&s[i+1]=='J')
                sum+=x;
            if(s[i]=='J'&&s[i+1]=='C')
                sum+=y;
            if(i>=1)
            {
                if(s[i]=='?')
                {
                    char k= s[i-1];
                    int j=i;
                    while(s[j]=='?')
                        j++;
                    char l=s[j];
                    i=j-1;
                    if(k!=l&&l!='\0')
                    {
                        if(k=='C') sum +=x;
                        if(k=='J') sum +=y;
                    }
                }
                    
            }
            i++;
        }
        cout<<"Case #"<<p<<": "<<sum<<endl;
    }
}