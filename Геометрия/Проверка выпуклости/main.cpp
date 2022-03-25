#include<iostream>

using namespace std;
typedef long double ld;

struct vect {
    ld x, y;

    vect() {}

    vect(ld _x, ld _y) {
        x = _x;
        y = _y;
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

int n, minus, plus;
vect points[110], vector1, vector2;
ld product;

int main() {
    freopen("convex.in", "r", stdin);
    freopen("convex.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> points[i];
    for (int i = 1; i < n; i++) {
        vector1 = points[i] - points[i - 1];
        minus = plus = 0;
        for (int j = 0; j < n; j++) {
            vector2 = points[j] - points[i - 1];
            product = vector1 % vector2;
            if (product < 0)
                minus++;
            if (product > 0)
                plus++;
        }
        if (minus != 0 && plus != 0) {
            cout << "no";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}