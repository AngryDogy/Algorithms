#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
const ll size=1e6;
ll tree[size], value[size];
bool was[size];
string letter;
ll n, k, x, y, v;
void push(ll v, ll l, ll r)
{
	if(was[v])
	{
		was[v]=0;
		tree[v]=(r-l)*value[v];
		was[2*v+1]=was[2*v+2]=1;
		value[2*v+1]=value[2*v+2]=value[v];
		value[v]=0;
	}
}
void relax(ll v, ll l, ll r)
{
	ll mid=l+(r-l)/2;
	push(2*v+1, l, mid);
	push(2*v+2, mid, r);
	tree[v]=tree[2*v+1]+tree[2*v+2];
	return;
}
void upd(ll v, ll l, ll r, ll L, ll R, ll val)
{
	if(r<=L || R<=l)
		return;
	if(L<=l && r<=R)
	{
		was[v]=1;
		value[v]=val;
		return;
	}
	push(v, l, r);
	ll mid=l+(r-l)/2;
	upd(2*v+1, l, mid, L, R, val);
	upd(2*v+2, mid, r, L, R, val);
	relax(v, l, r);
}
ll get(ll v, ll l, ll r, ll L, ll R)
{
	if(r<=L || R<=l)
		return 0;
	push(v, l, r);
	if(L<=l && r<=R)
		return tree[v];
	ll mid=l+(r-l)/2;
	ll lans=get(2*v+1, l, mid, L, R);
	ll rans=get(2*v+2, mid, r, L, R);
	return lans+rans;
}
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<k;i++)
	{
		cin>>letter;
		if(letter=="A")
		{
			cin>>x>>y>>v;
			upd(0, 0, n, x-1, y, v);
		}
		else
		{
			cin>>x>>y;
			cout<<get(0, 0, n, x-1, y)<<'\n';
		}
	}
	return 0;
}