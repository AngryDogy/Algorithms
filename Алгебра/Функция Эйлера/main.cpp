#include<iostream>
using namespace std;
int main()
{
	freopen("phi.in","r",stdin);
	freopen("phi.out","w",stdout);
	int v, ans, ch=0;
	cin>>v;
	ans=v;
	
	for(int i=2;i*i<=v;i++)
	{
		if(v%i==0)
		{
			while(v%i==0)
			{
				v=v/i;
				ch++;
			}
			ans=ans-(ans/i);

			
		}
	}
	if(v>1)
	{
		ans=ans-(ans/v);
	}
	cout<<ans;
	return 0;
}