#include<iostream>
#include<cmath>
#include<math.h>

using namespace std;
typedef long double ld;
const ld pi = acos((long double) -1);

struct vect {
    ld x, y;

    vect() {}

    vect(ld _x, ld _y) {
        x = _x;
        y = _y;
    }

    ld atn() {
        if (atan2(y, x) < 0)
            return atan2(y, x) + 2 * pi;
        else
            return atan2(y, x);
    }

    vect operator-(vect a) {
        return vect(x - a.x, y - a.y);
    }

    ld operator%(vect a) {
        return a.x * y - x * a.y;
    }

    friend istream &operator>>(istream &in, vect &a) {
        in >> a.x >> a.y;
        return in;
    }
};

vect a;
ld tg, atg, ans;

int main() {
    freopen("polarangle.in", "r", stdin);
    freopen("polarangle.out", "w", stdout);
    cout << fixed;
    cout.precision(15);
    cin >> a;
    atg = a.atn();
    cout << atg << ' ';
    atg = atg * (180 / pi);
    cout << atg;
    return 0;
}