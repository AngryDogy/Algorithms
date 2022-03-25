#include<iostream>

using namespace std;
typedef long long ll;
ll tree[5010][5010];
ll n, m, k, q, x, y, v, r1, r2, c1, c2;

void build(ll x, ll y, ll val) {
    for (ll i = x; i <= n; i = i | (i + 1)) {
        for (ll j = y; j <= m; j = j | (j + 1)) {
            tree[i][j] = tree[i][j] + val;
        }
    }
}

ll sum(ll x, ll y) {
    ll result = 0;
    for (ll i = x; i >= 0; i = (i & (i + 1)) - 1) {
        for (ll j = y; j >= 0; j = (j & (j + 1)) - 1) {
            result = result + tree[i][j];
        }
    }
    return result;
}

int main() {
    freopen("rsq2d.in", "r", stdin);
    freopen("rsq2d.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> q;
        if (q == 1) {
            cin >> x >> y >> v;
            build(x, y, v);
        } else {
            cin >> r1 >> r2 >> c1 >> c2;
            cout << sum(c1, c2) - sum(c1, r2 - 1) - sum(r1 - 1, c2) + sum(r1 - 1, r2 - 1) << '\n';
        }
    }
    return 0;
}