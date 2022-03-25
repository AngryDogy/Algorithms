#include<iostream>
using namespace std;
typedef long long ll;
ll tree[1000000], a[1000000];
ll n, m, v1, v2, v3;
void build( ll v, ll l, ll r)
{
	if(r-l==1)
	{
		tree[v]=a[l];
		return;
	}
	ll mid=l+(r-l)/2;
	build(2*v+1, l, mid);
	build(2*v+2, mid, r);
	tree[v]=tree[2*v+1]+tree[2*v+2];
}
void upd(ll v, ll l, ll r, ll pos, ll val)
{
	if(r-l==1)
	{
		tree[v]=tree[v]+val;
		return;
	}
	ll mid=l+(r-l)/2;
	if(pos<mid)
		upd(2*v+1, l, mid, pos, val);
	else
		upd(2*v+2, mid, r, pos, val);
	tree[v]=tree[2*v+1]+tree[2*v+2];
}
ll get(ll v, ll l, ll r, ll L, ll R)
{
	if(r<=L || R<=l)
		return 0;
	if(l>=L && r<=R)
		return tree[v];
	ll mid=l+(r-l)/2;
	ll lans=get(2*v+1, l, mid, L, R);
	ll rans=get(2*v+2, mid, r, L, R);
	return lans+rans;
}
int main()
{
	freopen("rsq2.in","r",stdin);
	freopen("rsq2.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++)
		cin>>a[i];
	build(0, 0, n);
	for(ll i=0;i<m;i++)
	{
		cin>>v1>>v2>>v3;
		if(v1==1)
			upd(0, 0, n, v2-1, v3);
		else
			cout<<get(0, 0, n, v2-1, v3)<<'\n';
	}
	return 0;
}