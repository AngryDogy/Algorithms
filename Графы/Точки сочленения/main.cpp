#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
vector <vector<ll>> g;
ll n, m, v1, v2, t = 0, ch = 0, root;
ll color[25000], tin[25000], tup[25000], ans[25000], was[25000];

void dfs(ll v, ll p) {
    ll child = 0;
    color[v] = 1;
    tin[v] = tup[v] = t;
    t++;
    for (int i = 0; i < g[v].size(); i++) {
        if (color[g[v][i]] == 1 && g[v][i] != p)
            tup[v] = min(tup[v], tin[g[v][i]]);
        if (color[g[v][i]] == 0) {
            dfs(g[v][i], v);
            tup[v] = min(tup[v], tup[g[v][i]]);
            if (tin[v] <= tup[g[v][i]] && v != root && was[v] == 0) {
                ans[ch] = v;
                ch++;
                was[v] = 1;
            }
            if (v == root)
                child++;

        }
    }
    if (v == root && child >= 2 && was[v] == 0) {
        ans[ch] = v;
        ch++;
        was[v] = 1;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    g.resize(n + 10);
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            root = i;
            dfs(i, -1);
        }
    }
    sort(ans, ans + ch);
    cout << ch << endl;
    for (int i = 0; i < ch; i++)
        cout << ans[i] << ' ';
    return 0;
}