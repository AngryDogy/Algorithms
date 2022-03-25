#include<iostream>
using namespace std;
typedef long long ll;
const ll inf=1e12;
const ll abroad=1e5*2;
ll room[1000000], tree[1000000];
ll n, v, z;
void build(ll v, ll l, ll r)
{
	if(r-l==1)
	{
		tree[v]=l;
		return;
	}
	ll mid=l+(r-l)/2;
	build(2*v+1, l, mid);
	build(2*v+2, mid, r);
	tree[v]=min(tree[2*v+1], tree[2*v+2]);
}
void upd(ll v, ll l, ll r, ll pos, ll val)
{
	if(r-l==1)
	{
		tree[v]=val;
		return;
	}
	ll mid=l+(r-l)/2;
	if(pos<mid)
		upd(2*v+1, l, mid, pos, val);
	else
		upd(2*v+2, mid, r, pos, val);
	tree[v]=min(tree[2*v+1], tree[2*v+2]);
}
ll get(ll v, ll l, ll r, ll L, ll R)
{
	if(r<=L || R<=l)
		return inf;
	if(L<=l && r<=R)
		return tree[v];
	ll mid=l+(r-l)/2;
	ll lans=get(2*v+1, l, mid, L, R);
	ll rans=get(2*v+2, mid, r, L, R);
	return min(lans, rans);
}

int main()
{
	freopen("house36.in","r",stdin);
	freopen("house36.out","w",stdout);
	cin>>n;
	build(0, 1, abroad);


	for(int i=0;i<n;i++)
	{
		cin>>v;
		if(v>0)
		{
			if(room[v]==0)
			{
				cout<<v<<'\n';
				upd(0, 1, abroad, v, inf);
				room[v]=1;
			}
			else
			{
				z=get(0, 1, abroad, v+1, abroad);
				upd(0, 1, abroad, z, inf);
				room[z]=1;
				cout<<z<<'\n';
			}
		}
		else
		{
			v=abs(v);
			upd(0, 1, abroad, v, v);
			room[v]=0;
		}
	}
	return 0;
}