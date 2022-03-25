#include<iostream>
using namespace std;
int main()
{
	freopen("pascal.in","r",stdin);
	freopen("pascal.out","w",stdout);
	long long n,tp[100][100];
	cin>>n;
	tp[1][1]=1;
	tp[2][1]=1;
	tp[2][2]=1;
	if(n==0)
		cout<<1;
	if(n==1)
		cout<<1<<' '<<1;
	if(n!=0 && n!=1)
	{
		for(int i=3;i<=n+1;i++)
		{
			for(int j=1;j<=i;j++)
			{
				if(j==1 || j==i)
					tp[i][j]=1;
				else
					tp[i][j]=tp[i-1][j]+tp[i-1][j-1];
			}
			if(i==n+1)
			{
				for(int k=n+1;k==n+1;k++)
				{
					for(int p=1;p<=k;p++)
					{
						cout<<tp[k][p]<<' ';
					}
				}
				
			}

		}
	}

	return 0;
}