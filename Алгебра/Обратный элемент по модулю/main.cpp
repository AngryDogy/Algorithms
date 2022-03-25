#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    freopen("invmod.in", "r", stdin);
    freopen("invmod.out", "w", stdout);

    int v, m;
    int a, b, c = 1, ans;
    int E[100][100], q = 0;
    cin >> v >> m;
    a = max(v, m);
    b = min(v, m);
    E[1][q] = a;
    E[2][q] = b;
    q++;
    while (c != 0) {
        c = a % b;
        if (c == 0) {
            ans = b;
            break;
        }
        a = b;
        b = c;
        E[1][q] = a;
        E[2][q] = b;
        q++;
    }
    if (ans != 1) {
        cout << "NO";
    } else {
        E[1][q] = ans;
        E[2][q] = 0;
        E[3][q] = 1;
        E[4][q] = 0;
        for (int i = 1; i <= q; i++) {
            E[3][q - i] = E[4][q - i + 1];
            E[4][q - i] = E[3][q - i + 1] - E[4][q - i + 1] * (E[1][q - i] / E[2][q - i]);
        }

        int x, y;
        x = E[3][0];
        y = E[4][0];
        if (v * x + m * y != 1) {
            swap(x, y);
        }
        cout << "YES" << endl;
        x = (x % m + m) % m;
        cout << x;
    }

    return 0;
}