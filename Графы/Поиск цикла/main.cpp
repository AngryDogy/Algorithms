#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;
const ll size = 2 * 1e5;
vector <vector<ll>> g;
ll n, m, v1, v2, point = -1e6, ch = 0;
ll color[size], ans[size];
bool out = 0;

void dfs(ll v) {
    color[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        if (color[g[v][i]] == 1) {
            point = g[v][i];
            ans[ch] = v;
            ch++;
            return;
        }
        if (color[g[v][i]] == 0) {
            dfs(g[v][i]);
            if (out == 1)
                return;
            if (v == point) {
                ans[ch] = v;
                ch++;
                out = 1;
                return;
            }
            if (ch > 0) {
                ans[ch] = v;
                ch++;
                return;
            }
        }

    }
    color[v] = 2;
}

int main() {
    freopen("cicle.in", "r", stdin);
    freopen("cicle.out", "w", stdout);
    cin >> n >> m;
    g.resize(n + 5);
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        g[v1].push_back(v2);
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            dfs(i);
            if (ch > 0)
                break;
        }
    }
    if (ch > 0) {
        cout << "YES" << endl;
        for (int i = ch - 1; i >= 0; i--)
            cout << ans[i] << ' ';
    } else
        cout << "NO";
    return 0;
}