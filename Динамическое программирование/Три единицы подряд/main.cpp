#include<iostream>
using namespace std;
int a[200][200];
int main()
{
	freopen("ones.in","r",stdin);
	freopen("ones.out","w",stdout);
	int n,ans;
	cin>>n;
	a[0][0]=1;
	a[0][1]=1;
	if(n==1)
	{
		cout<<2;
	}
	else
	{
		for(int i=1;i<n;i++)
		{
			a[i][0]=a[i-1][0]+a[i-1][1]+a[i-1][2];
            a[i][1]=a[i-1][0];
			a[i][2]=a[i-1][1];
		}
		ans=a[n-1][0]+a[n-1][1]+a[n-1][2];
		cout<<ans;
	}
	return 0;
}