#include<iostream>
using namespace std;
typedef long double ld;
typedef long long ll;
const ld pi=acosl((ld)-1);
const ld eps=1e-9;
struct vect 
{
	ll x, y;
	vect(){}
	vect(ll _x, ll _y)
	{
		x=_x;
		y=_y;
	}
	ld a(ld a, ld b)
	{
		if(atan2l(a, b)<0)
			return atan2l(a, b)+2*pi;
		else
			return atan2l(a,b);
	}
	ll operator%(vect a)
	{
		return x*a.y-y*a.x;
	}
	ll operator*(vect a)
	{
		return x*a.x+y*a.y;                                                                                                           
	}
	vect operator-(vect a)
	{
		return vect(x-a.x,y-a.y);
	}
	bool operator==(vect a)
	{
		return x==a.x && y==a.y;
	}
	friend istream& operator >>(istream &in, vect &a)
	{
		in >> a.x >> a.y;
		return in;
	}
};
ld absl(ld val)
{
	if(val<0)
		return -val;
	else
		return val;
}
ll n;
ld angle=0;
vect mainpoint, points[1000000], v1, v2;
int main()
{
	freopen("inside.in","r",stdin);
	freopen("inside.out","w",stdout);
	cin>>n>>mainpoint;
	for(int i=0;i<n;i++)
	{
		cin>>points[i];
		if(mainpoint==points[i])
		{
			cout<<"YES";
			return 0;
		}
	}
	points[n]=points[0];
	for(int i=0;i<n;i++)
	{
		v1=points[i]-mainpoint;
		v2=points[i+1]-mainpoint;
		angle=angle+atan2l(v1%v2, v1*v2);
	}
	if(absl(2*pi-absl(angle))<eps || absl(pi-absl(angle)<eps))
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}