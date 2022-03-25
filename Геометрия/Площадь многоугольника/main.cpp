#include<iostream>
using namespace std;
typedef long double ld;
struct vect
{
	ld x, y;
	vect(){}
	vect(ld _x, ld _y)
	{
		x=_x;
		y=_y;
	}
	vect operator-(vect a)
	{
		return vect(x-a.x, y-a.y);
	}
	ld operator%(vect a)
	{
		return a.x*y-x*a.y;
	}
	friend istream& operator >>(istream &in, vect &a)
	{
		in >> a.x >> a.y;
		return in;
	}
};
int n, minus=0, plus=0;
vect points[100000], vector1, vector2;
ld product, ans;
int main()
{
	freopen("polygonarea.in","r",stdin);
	freopen("polygonarea.out","w",stdout);
	cout<<fixed;
	cout.precision(6);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>points[i];
	for(int i=2;i<n;i++)
	{
		vector1=points[i]-points[0];
		vector2=points[i-1]-points[0];
		product=vector1%vector2;
		ans=ans+product/2;
	}
	cout<<ans;
	return 0;
}