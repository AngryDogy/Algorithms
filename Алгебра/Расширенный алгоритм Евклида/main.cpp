#include<iostream>
#include <math.h> 
using namespace std;
int M[1000][1000];
int main()
{
	freopen("exteuclid.in","r",stdin);
	freopen("exteuclid.out","w",stdout);
	int V1,V2;
	int a,b,c=1;
	int ans,q=0;
	cin>>V1>>V2;
	a=max(V1,V2);
	b=min(V1,V2);
	a=abs(a);
	b=abs(b);
	M[1][q]=a;
	M[2][q]=b;
	q++;
	while(c!=0)
	{
		c=a%b;
		if(c==0)
		{
			ans=b;
			break;
		}
		a=b;
		b=c;
		M[1][q]=a;
		M[2][q]=b;
		q++;
	}
	M[1][q]=ans;
	M[2][q]=0;
	M[3][q]=1;
	M[4][q]=0;
	
	for(int i=1;i<=q;i++)
	{
		M[3][q-i]=M[4][q-i+1];
		M[4][q-i]=M[3][q-i+1]-M[4][q-i+1]*(M[1][q-i]/M[2][q-i]);
	}
	int x=M[3][0];
	int y=M[4][0];
	if(V1*x+V2*y==ans)
	{
		cout<<x<<' '<<y;
	}
	else
	{
		cout<<y<<' '<<x;
	}
	return 0;
}