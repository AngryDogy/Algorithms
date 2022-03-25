#include<iostream>
using namespace std;
struct node
{
	int n[2], x[2];
	bool t;
	node()
	{
		n[0]=n[1]=0;
		x[0]=x[1]=-1;
	}
};
node trie[1500000];
int n, val, t=0, ans, out, k;
void add(int v)
{
	int cur=0;
	for(int i=21;i>=0;i--)
	{
		int b=(v>>i) & 1;
		if(trie[cur].x[b]==-1)
		{
			trie[cur].x[b]=++t;
		}
		trie[cur].n[b]++;
		cur=trie[cur].x[b];
	}
	trie[cur].t=1;
}
void erase(int v)
{
	int cur=0;
	for(int i=21;i>=0;i--)
	{
		int b=(v>>i)&1;
		trie[cur].n[b]--;
		cur=trie[cur].x[b];
	}
}
int kth(int k)
{
	int cur=0, ans=0;
	for(int i=21;i>=0;i--)
	{
		if(trie[cur].n[0]>=k)
			cur=trie[cur].x[0];
		else
		{
			k=k-trie[cur].n[0];
			cur=trie[cur].x[1];
			ans=ans|(1<<i);
		}	
	}
	return ans;	
}
int main()
{
	freopen("machine.in","r",stdin);
	freopen("machine.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>val;
		if(val>0)
		{
			add(val);
			k++;
		}
		if(val<0)
		{
			val=abs(val);
			ans=kth(val);
			erase(ans);
			cout<<ans<<' ';
			k--;
		}
		if(val==0)
		{
			cout<<'\n';
			for(int i=1;i<=k;i++)
			{
				out=kth(1);
				cout<<out<<' ';
				erase(out);
			}
			k=0;
			cout<<'\n';
		}
	}
	return 0;
}