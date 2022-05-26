#include<bits/stdc++.h>
#include<vector>
using namespace std;
int getPowerCouple2021(int fn, int fe, vector<int> ff, vector<int> ft, vector<int> fw) {
	long long int i,j,k,l;
	vector<int> vec[fn];
	for(i=0;i<fe;i++)
	{
		vec[ff[i]-1].push_back(fw[i]);
	}
	for(i=0;i<fe;i++)
	{
		vec[ft[i]-1].push_back(fw[i]);
	}
	for(i=0;i<fn;i++)
	{
		sort(vec[i].begin(),vec[i].end());
	    std::unordered_set<int> s(vec[i].begin(), vec[i].end());
        vec[i].assign(s.begin(), s.end());	
	}
	int s[fn][fn];
	memset(s,0,sizeof(s));
	for(i=0;i<fn-1;i++)
	{
		for(j=i+1;j<fn;j++)
		{
			for(k=0;k<vec[i].size();k++)
			{
				for(l=0;l<vec[j].size();l++)
				{
					if(vec[i][k]==vec[j][l])
						{
							s[i][j]++;
						}
				}
			}
		}
	}
	long long int hel=0,ans=-1;
	for(i=0;i<fn;i++)
	{
		for(j=0;j<fn;j++)
		{
			if(hel<=s[i][j])
			{
				ans=max(ans,(i+1)*(j+1));
				hel=s[i][j];
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