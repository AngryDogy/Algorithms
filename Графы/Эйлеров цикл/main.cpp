#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int size = 1e5 + 10;
vector <vector<pair < int, int>>>
g;
int n, m, v1, v2, k = 0;
ll ch = 0;
int color[size], ans[size];
bool even = 1;

void dfs(ll v) {
    while (g[v].size() != 0) {
        if (color[g[v][0].second] != 0) {
            auto it = g[v].begin();
            g[v].erase(it);
            continue;
        }
        int to = g[v][0].first;
        int edge = g[v][0].second;
        auto it = g[v].begin();
        g[v].erase(it);
        k++;
        color[edge] = 1;
        dfs(to);
    }
    ans[ch] = v;
    ch++;
    //color[v]=1;

}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    g.resize(n + 10);
    for (int i = 1; i <= m; i++) {
        cin >> v1 >> v2;
        g[v1].push_back(make_pair(v2, i));
        g[v2].push_back(make_pair(v1, i));

    }
    for (int i = 1; i <= n; i++) {
        if (g[i].size() % 2 != 0) {
            even = 0;
            break;
        }
    }
    if (even == 0)
        cout << "No solution";
    else {
        int key = 1;
        while (1) {
            if (g[key].size() > 0) {
                dfs(key);
                break;
            }
            key++;
        }
        if (k < m)
            cout << "No solution";
        else {
            cout << "Solution exists" << endl;
            for (ll i = ch - 1; i >= 0; i--)
                cout << ans[i] << ' ';
        }
    }
    return 0;
}