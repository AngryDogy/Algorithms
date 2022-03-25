#include<iostream>
using namespace std;


long long w, n, m, p;
long long dp[110][11000];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
        cin>>w>>n;
        for(int i=1;i<=n;i++)
        {
         	cin>>p>>m;
         	for(int j=1;j<=w;j++)
         	{
         		if(j-p>=0)
         			dp[i][j]=max(dp[i-1][j], dp[i-1][j-p]+m);
         		else
         			dp[i][j]=dp[i-1][j];
         	}

         	
         }

        cout<<dp[n][w];
	
	return 0;
}