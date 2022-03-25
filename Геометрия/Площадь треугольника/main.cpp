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
vect a, b, c, vector1, vector2, product ;
ld v1, v2, s, ans;
int main()
{
	freopen("trianglearea.in","r",stdin);
	freopen("trianglearea.out","w",stdout);
	cout<<fixed;
	cout.precision(15);
	cin>>a>>b>>c;
	vector1=b-a;
	vector2=c-a;
	s=abs(vector1%vector2);
	if(s==0)
		cout<<-1;
	else
	{
		ans=s/2;
		cout<<ans;
	}
	return 0;
}