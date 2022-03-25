#include<iostream>
using namespace std;
long long n,l,A[1000],C[1000],L[10100];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>l;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>C[i];
	}
	
	for(int i=0;i<=l;i++)
	{
		if(i!=0)
		{
			L[i]=max(L[i], L[i-1]);
		}
		for(int j=0;j<n;j++)
		{
			if(i+A[j]<=l)
			{
				L[i+A[j]]=max(L[i+A[j]], L[i]+C[j]);
			}
			
		}
	}
	cout<<L[l];
	return 0;
}