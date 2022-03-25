#include<iostream>

using namespace std;
typedef long long ll;
const ll inf = 1e6;
ll a[inf], tree[inf], ans[inf];
ll n;

void upd(ll v, ll l, ll r, ll pos, ll val) {
    if (r - l == 1) {
        tree[v] += val;
        return;
    }
    ll mid = l + (r - l) / 2;
    if (pos < mid)
        upd(2 * v + 1, l, mid, pos, val);
    else
        upd(2 * v + 2, mid, r, pos, val);
    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
}

ll get(ll v, ll l, ll r, ll L, ll R) {
    if (r <= L || R <= l)
        return 0;
    if (L <= l && r <= R)
        return tree[v];
    ll mid = l + (r - l) / 2;
    ll lans = get(2 * v + 1, l, mid, L, R);
    ll rans = get(2 * v + 2, mid, r, L, R);
    return lans + rans;
}

int main() {
    freopen("inversions.in", "r", stdin);
    freopen("inversions.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i == 1) {
            upd(0, 1, n + 1, a[i], 1);
        } else {
            upd(0, 1, n + 1, a[i], 1);
            ans[a[i]] = get(0, 1, n + 1, a[i] + 1, n + 1);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}