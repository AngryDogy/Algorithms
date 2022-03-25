#include<iostream>
using namespace std;
const int size=1e6;
int n1, n2;
int x[size], y[size], lcs[1010][1010];
int main()
{
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);

	cin>>n1;
	for(int i=0;i<n1;i++)
	{
		cin>>x[i];

	}
	cin>>n2;
	for(int i=0;i<n2;i++)
	{
		cin>>y[i];

	}
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		{
			/*if(i==0 || j==0)
			{
				lcs[i][j]=0;
				continue;
			}*/
			if(x[i]==y[j])
			{
				if(i-1>=0 && j-1>=0) 
					lcs[i][j]=lcs[i-1][j-1]+1;
				else
					lcs[i][j]=lcs[i][j]+1;
			}
			else
			{
				
				if(j-1<0 && i-1<0)
					continue;
				if(j-1<0)
				{
					lcs[i][j]=lcs[i-1][j];
					continue;
				}
				if(i-1<0)
				{
					lcs[i][j]=lcs[i][j-1];
					continue;

				}
				lcs[i][j]=max(lcs[i][j-1], lcs[i-1][j]);
			}
			

		}
	}
	cout<<lcs[n1-1][n2-1];
		
	return 0;
}