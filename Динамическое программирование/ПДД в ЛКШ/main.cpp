#include<iostream>
using namespace std;
int n, m, val, k=1;
int dp[1010][1010], ans[1000000];
int main()
{
	freopen("pdd.in","r",stdin);
	freopen("pdd.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>val;
			dp[i][j]=dp[i][j]+val;
			if(i==0 && j==0)
				continue;
			if(i-1>=0 && j-1<0)
			{
				dp[i][j]=dp[i][j]+dp[i-1][j];
				continue;
			}
			if(j-1>=0 && i-1<0)
			{
				dp[i][j]=dp[i][j]+dp[i][j-1];
				continue;
			}
			dp[i][j]=min(dp[i-1][j]+dp[i][j], dp[i][j-1]+dp[i][j]);

		}

	}
	int x=n-1, y=m-1;
	ans[0]=x;
	ans[1]=y;
	int ch=2;
	while(x!=0 || y!=0)
	{
		if(x-1<0)
		{
			y--;
			ans[ch]=x;
			ans[ch+1]=y;
			ch=ch+2;
			k++;
			continue;
		}
		if(y-1<0)
		{
			x--;
			ans[ch]=x;
			ans[ch+1]=y;
			ch=ch+2;
			k++;
			continue;
		}
		if(dp[x][y-1]>dp[x-1][y])
		{
			x--;
			ans[ch]=x;
			ans[ch+1]=y;
			ch=ch+2;
			k++;
		}
		else
		{
			y--;
			ans[ch]=x;
			ans[ch+1]=y;
			ch=ch+2;
			k++;
		}
	}
	cout<<dp[n-1][m-1]<<endl;
	cout<<k<<endl;
	for(int i=ch-1;i>=0;i=i-2)
	{
		cout<<ans[i-1]+1<<' '<<ans[i]+1<<endl;
	}	


	return 0;
}