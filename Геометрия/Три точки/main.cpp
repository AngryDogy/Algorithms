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
vect a, b, c, vector1, vector2;
ld product;
int main()
{
	freopen("threepoints.in","r",stdin);
	freopen("threepoints.out","w",stdout);
	cin>>a>>b>>c;
	vector1=b-a;
	vector2=c-a;
	product=vector1%vector2;
	if(product==0)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}