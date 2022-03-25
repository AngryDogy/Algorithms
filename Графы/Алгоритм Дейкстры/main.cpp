#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
vector <vector<pair < ll, ll>>>
g;
set <pair<ll, ll>> q;
const ll size = 1e6, inf = 1e9;
ll n, m, a, v1, v2, val;
ll d[size], color[size];

void deik(ll v) {
    color[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        if (d[g[v][i].first] > d[v] + g[v][i].second) {
            q.erase(make_pair(d[g[v][i].first], g[v][i].first));
            d[g[v][i].first] = d[v] + g[v][i].second;
            q.insert(make_pair(d[g[v][i].first], g[v][i].first));
        }
    }
    if (q.size() > 0) {
        auto it = q.begin();
        ll u = it->second;
        q.erase(it);
        deik(u);
    }

}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m >> a;
    fill(d, d + n + 10, inf);
    g.resize(n + 10);
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2 >> val;
        g[v1].push_back(make_pair(v2, val));
    }
    d[a] = 0;
    deik(a);
    for (int i = 1; i <= n; i++) {
        if (d[i] == inf)
            cout << -1 << ' ';
        else
            cout << d[i] << ' ';
    }
    return 0;
}