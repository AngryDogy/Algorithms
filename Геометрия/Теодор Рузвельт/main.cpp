#include<iostream>	
#include<algorithm>
using namespace std;
typedef long long ll;
const ll size=1e6;
struct vect
{
	ll x, y;
	vect(){}
	vect(ll _x, ll _y)
	{
		x=_x;
		y=_y;
	}
	ll len()
	{
		return x*x+y*y;
	}
	bool operator==(vect a)
	{
		return x==a.x && y==a.y;
	}
	vect operator-(vect a)
	{
		return vect(x-a.x, y-a.y);
	}
	ll operator%(vect a)
	{
		return x*a.y-y*a.x;
	}
	vect operator=(vect a)
	{
		return vect(x=a.x, y=a.y);
	}
	friend istream& operator >>(istream &in, vect &a)
	{
		in >> a.x >> a.y;
		return in;
	}
};
ll absl(ll val)
{
	if(val<0)
		return -val;
	else
		return val;
}
bool cmp(vect a, vect b)
{
	if(a%b==0)
		return a.len()<b.len();
	else
		return a%b>0;
}
ll n, m, k, l, r, mid, ans=0, ch, check=0;
vect ship[size], rocket, point=vect(1e17, 1e17);
int main()
{
	freopen("theodore.in","r",stdin);
	freopen("theodore.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		cin>>ship[i];
		if(ship[i].y<point.y)
			point=ship[i];
		if(ship[i].y==point.y && ship[i].x<point.x)
			point=ship[i];
	}
	for(int i=0;i<n;i++)
	{
		if(check>0 && ship[i]==point)
		{
			ship[i]=vect(1e17, 1e17);
			check++;
			continue;
		}
		if(ship[i]==point)
			check++;
		ship[i]=ship[i]-point;
	
	}
	n=n-(check-1);	
	sort(ship, ship+n, cmp);
	for(int i=0;i<m;i++)
	{
		cin>>rocket;
		rocket=rocket-point;
		l=n-1;
		r=1;
		ch=0;
		if(ship[l]%rocket>0 || ship[r]%rocket<0)
			continue;
		while(r<=l)
		{
			mid=l+(r-l)/2;
			if(ship[mid]%rocket==0)
			{
				if(ship[mid].len()>=rocket.len())
				{
					ans++;
					ch++;
					break;
				}
				else
				{
					ch++;
					break;
				}
			}
			if(ship[mid]%rocket>0)
				r=mid+1;
			if(ship[mid]%rocket<0)
				l=mid-1;
		}
		if(ch>0)
			continue;
		else
		{
			if((absl(ship[l]%rocket))+(absl(ship[r]%rocket))<=(absl(ship[l]%ship[r])))
				ans++;
		}
	}
	if(ans>=k)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}