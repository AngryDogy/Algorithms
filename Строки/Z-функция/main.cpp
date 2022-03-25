#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int size=1e6;
string s;
int z[size], l, r, j;
int main()
{
    freopen("z.in","r",stdin);
    freopen("z.out","w",stdout);
   	cin>>s;
   	l=r=0;
   	for(int i=1;i<s.size();i++)
   	{

		if(i<=r)
		{
			z[i]=min(r-i+1, z[i-l]);
			if(z[i]==0)
				j=i;
			else
			{
				if(i+z[i]<s.size())
					j=i+z[i];
				else
					continue;
			}
		}
		else
		{
			j=i;
			
		}
		while(s[z[i]]==s[j])
		{
			r=j;
			l=i;
			z[i]++;
			j++;
			if(j+1>s.size())
				break;

		}
   	}
   	for(int i=0;i<s.size();i++)
   	{
   		cout<<z[i]<<' ';
   	}
	return 0;
}