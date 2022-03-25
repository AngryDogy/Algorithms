#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll inf = 1e9;
ll n, m, val, q1, q2;
ll g[500][500], f[500][500];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> val;
            if (val == -1001) {
                g[i][j] = inf;
                f[i][j] = inf;
            } else {
                g[i][j] = val;
                f[i][j] = val;
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (f[i][k] != inf && f[k][j] != inf)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> q1 >> q2;
        if (f[q1][q2] == inf)
            cout << "No path" << endl;
        else
            cout << f[q1][q2] << endl;

    }
    return 0;
}