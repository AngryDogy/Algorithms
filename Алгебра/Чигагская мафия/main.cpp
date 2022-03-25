#include<iostream>
using namespace std;
int main()
{
	freopen("chicago.in","r",stdin);
	freopen("chicago.out","w",stdout);
	int v1,v2;
	int a,b,c=1,gcd;
	int P[100][100],q=0;
	cin>>v1>>v2;
	a=max(v1,v2);
	b=min(v1,v2);
	P[1][q]=a;
	P[2][q]=b;
	q++;
	while(c!=0)
	{
		c=a%b;
		if(c==0)
		{
			gcd=b;
			break;
		}
		a=b;
		b=c;
		P[1][q]=a;
		P[2][q]=b;
		q++;
	}
	if(gcd!=1)
	{
		cout<<"no solution";
	}
	else
	{
		P[1][q]=1;
		P[2][q]=0;
		P[3][q]=1;
		P[4][q]=0;
		for(int i=1;i<=q;i++)
		{
			P[3][q-i]=P[4][q-i+1];
			P[4][q-i]=P[3][q-i+1]-P[4][q-i+1]*(P[1][q-i]/P[2][q-i]);
		}
		int x,y;
		x=P[3][0];
		y=P[4][0];
		if(v1*x+v2*y!=1)
		{
			swap(x,y);
		}
		x=abs(x);
		y=abs(y);
		cout<<x<<' '<<y;
	}


	return 0;
}