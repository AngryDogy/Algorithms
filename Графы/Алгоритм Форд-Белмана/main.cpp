#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e9;
const ll size=1e3;
vector<vector<pair<ll, ll>>> g;
ll n, m, v1, v2, p;
ll ford[size];
int main()
{
	freopen("shortest.in","r",stdin);
	freopen("shortest.out","w",stdout);
	cin>>n>>m;
	g.resize(n*m+10);
	fill(ford, ford+n+10, inf);
	for(int i=0;i<m;i++)
	{
		cin>>v1>>v2>>p;
	        g[v1].push_back(make_pair(v2, p));
			
	}
	ford[1]=0;
	for(int k=0;k<n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<g[i].size(); j++)
			{
				if(ford[i]!=inf)
					ford[g[i][j].first]=min(ford[g[i][j].first], ford[i]+g[i][j].second);	
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(ford[i]==inf)
			cout<<30000<<' ';
	        else
	        	cout<<ford[i]<<' ';
	}
	return 0;
}
