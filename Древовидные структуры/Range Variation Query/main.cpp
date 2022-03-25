#include<iostream>

using namespace std;
typedef long long ll;
const ll infminus = -100000000000000000;
const ll infalot = 100000000000000000;
ll tree[10000000], TREE[10000000], a[10000000];
ll n, v1, v2;

void build(ll v, ll l, ll r) {
    if (r - l == 1) {
        tree[v] = a[l];
        TREE[v] = a[l];
        return;
    }
    ll mid = l + (r - l) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);
    tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
    TREE[v] = min(TREE[2 * v + 1], TREE[2 * v + 2]);
}

ll getmax(ll v, ll l, ll r, ll L, ll R) {
    if (r <= L || R <= l)
        return infminus;
    if (l >= L && r <= R)
        return tree[v];
    ll mid = l + (r - l) / 2;
    ll lans = getmax(2 * v + 1, l, mid, L, R);
    ll rans = getmax(2 * v + 2, mid, r, L, R);
    return max(lans, rans);
}

ll getmin(ll v, ll l, ll r, ll L, ll R) {
    if (r <= L || R <= l)
        return infalot;
    if (l >= L && r <= R)
        return TREE[v];
    ll mid = l + (r - l) / 2;
    ll lans = getmin(2 * v + 1, l, mid, L, R);
    ll rans = getmin(2 * v + 2, mid, r, L, R);
    return min(lans, rans);
}

void upd(ll v, ll l, ll r, ll pos, ll val) {
    if (r - l == 1) {
        tree[v] = val;
        TREE[v] = val;
        return;
    }
    ll mid = l + (r - l) / 2;
    if (pos < mid)
        upd(2 * v + 1, l, mid, pos, val);
    else
        upd(2 * v + 2, mid, r, pos, val);
    tree[v] = max(tree[v * 2 + 1], tree[2 * v + 2]);
    TREE[v] = min(TREE[2 * v + 1], TREE[2 * v + 2]);
}

int main() {
    freopen("rvq.in", "r", stdin);
    freopen("rvq.out", "w", stdout);
    for (ll i = 1; i <= 100001; i++)
        a[i] = i * i % 12345 + i * i * i % 23456;
    build(0, 1, 100001);
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> v1 >> v2;
        if (v1 > 0) {
            cout << getmax(0, 1, 100001, v1, v2 + 1) - getmin(0, 1, 100001, v1, v2 + 1) << '\n';
        } else {
            v1 = abs(v1);
            upd(0, 1, 100001, v1, v2);
        }
    }
    return 0;
}