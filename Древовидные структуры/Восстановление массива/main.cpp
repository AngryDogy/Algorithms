#include<iostream>

using namespace std;
typedef long long ll;
const ll size = 1e6;
const ll inf = 1e17;
const ll minusinf = -1e17;
const ll two = 1 << 17;
ll n, m, l, r, val, ch = 0, check;
ll tree[size], TREE[size], save[size];

void push(ll v) {
    tree[2 * v + 1] = max(tree[v], tree[2 * v + 1]);
    tree[2 * v + 2] = max(tree[v], tree[2 * v + 2]);
}

void build(ll v, ll l, ll r) {
    push(v);
    if (r - l == 1) {
        if (tree[v] == minusinf)
            TREE[v] = inf;
        else
            TREE[v] = tree[v];
        return;
    }
    ll mid = l + (r - l) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);
    TREE[v] = min(TREE[2 * v + 1], TREE[2 * v + 2]);
}

void upd(ll v, ll l, ll r, ll L, ll R, ll val) {
    if (r <= L || R <= l)
        return;
    if (L <= l && r <= R) {
        tree[v] = max(tree[v], val);
        return;
    }
    ll mid = l + (r - l) / 2;
    upd(2 * v + 1, l, mid, L, R, val);
    upd(2 * v + 2, mid, r, L, R, val);
}

ll get(ll v, ll l, ll r, ll L, ll R) {
    if (r <= L || R <= l)
        return inf;
    if (L <= l && r <= R)
        return TREE[v];
    ll mid = l + (r - l) / 2;
    ll lans = get(2 * v + 1, l, mid, L, R);
    ll rans = get(2 * v + 2, mid, r, L, R);
    return min(lans, rans);
}

int main() {
    freopen("rmq.in", "r", stdin);
    freopen("rmq.out", "w", stdout);
    cin >> n >> m;
    fill(TREE, TREE + two * 5 + n, inf);
    fill(tree, tree + two * 5 + n, minusinf);
    for (int i = 0; i < m; i++) {
        cin >> l >> r >> val;
        upd(0, 0, two, l - 1, r, val);
        save[ch] = l;
        save[ch + 1] = r;
        save[ch + 2] = val;
        ch = ch + 3;
    }
    build(0, 0, two);
    for (int i = 0; i < ch; i = i + 3) {
        check = get(0, 0, two, save[i] - 1, save[i + 1]);
        if (check != save[i + 2]) {
            cout << "inconsistent" << '\n';
            return 0;
        }
    }
    cout << "consistent" << '\n';
    ll k = two - 1, x = 0;
    while (x < n) {
        if (TREE[k] == inf)
            cout << 0 << ' ';
        else
            cout << TREE[k] << ' ';
        k++;
        x++;
    }
    return 0;
}