#include<iostream>
#include<algorithm>
using namespace std;
int INF=-1000000000;
int A[300001],N,n=1,V;
void pushup(int v)
{
	if(A[v]>A[v/2])
	{
		swap(A[v],A[v/2]);
		pushup(v/2);
	}
	return;

}
void pushdown(int v)
{
	if(2*v>=n)
	{
			return;
	}
	if(A[v]<A[2*v] || A[v]<A[2*v+1])
	{
		
		if(A[2*v]>A[2*v+1])
		{
			swap(A[2*v],A[v]);
			pushdown(2*v);
		}
		else
		{
			swap(A[2*v+1],A[v]);
			pushdown(2*v+1);

		}
		return;
	}
}
void bye()
{
	cout<<A[1]<<endl;
	A[1]=A[n-1];
	A[n-1]=INF;
	n--;
	N--;
	pushdown(1);
	return;
}
int main()
{
	freopen("professor.in","r",stdin);
	freopen("professor.out","w",stdout);
	cin>>N;
	fill(A,A+N+1,INF);
	A[0]=-INF;
	while(N!=0)
	{	
		cin>>V;
		if(V!=0)
		{
			A[n]=V;
			pushup(n);
			n++;

		}
		else
		{
			bye();
		}
	}
	return 0;
}