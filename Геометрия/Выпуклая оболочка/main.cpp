#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long double ld;
typedef long long ll;
const ld pi=acos((ld)-1);
const ld eps=1e-7;
struct vect
{
	ll x, y;
	vect(){}
	vect(ll _x, ll _y)
	{
		x=_x;
		y=_y;
	}
	/*ld atn()
	{
		if(atan2(y, x)<0)
			return atan2(y,x)+2*pi;
		else
			return atan2(y, x);
	}*/
	ll len()
	{
		return x*x+y*y;
	}
	ld lenn()
	{
		return sqrtl(x*x+y*y);
	}
	ll operator%(vect a)
	{
		return x*a.y-y*a.x;
	}
	vect operator-(vect a)
	{
		return vect(x-a.x, y-a.y);
	}

	friend istream& operator >>(istream &in,vect &a)
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
bool cmp( vect a, vect b)
{
	if(a%b==0)
		return a.len()<b.len();
	else
		return a%b>0;
}
ll n, cnt=2, ch=2;
ld p=0;
vector<vect> ans;
vect point[1000000], mn=vect(1e17, 1e17), v1, v2;
int main()
{
	freopen("convex.in","r",stdin);
	freopen("convex.out","w",stdout);
	cout<<fixed;
	cout.precision(10);

	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>point[i];
		if(point[i].y<mn.y)
		{
			mn.x=point[i].x;
			mn.y=point[i].y;
		}
		if(mn.y==point[i].y && point[i].x<mn.x)
			mn.x=point[i].x;
	}
	for(int i=0;i<n;i++)
		point[i]=point[i]-mn;
	sort(point, point+n, cmp);
	ans.push_back(point[0]);
	ans.push_back(point[1]);
	while(ch<n)
	{
		v1=point[ch]-ans[cnt-1];
		v2=ans[cnt-1]-ans[cnt-2];
		if(v2%v1==0)
		{
			ans.pop_back();
			ans.push_back(point[ch]);
			ch++;
			continue;
		}
		if(v2%v1>0)
		{
			ans.push_back(point[ch]);
			cnt++;
		}
		else
		{

			ans.pop_back();
			cnt--;
			v1=point[ch]-ans[cnt-1];
			v2=ans[cnt-1]-ans[cnt-2];
			while(v2%v1<0)
			{
				ans.pop_back();
				cnt--;
				v1=point[ch]-ans[cnt-1];
				v2=ans[cnt-1]-ans[cnt-2];
			}
			ans.push_back(point[ch]);
			cnt++;
			
		}
		ch++;
	}
	for(int i=1;i<cnt;i++)
	{
		v1=ans[i]-ans[i-1];
		p=p+v1.lenn();
	}
	v1=ans[cnt-1];
	p=p+v1.lenn();
	cout<<p;
	return 0;
}