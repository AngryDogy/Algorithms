#include<bits/stdc++.h>

using namespace std;
const int size = 1e6;
vector <vector<int>> g;
vector <vector<int>> G;
stack<int> q;
int n, m, v1, v2, v, k = 1;
int color[size], COLOR[size], ans[size];

void dfs(int v) {

    color[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        if (color[g[v][i]] == 0) {
            dfs(g[v][i]);
        }
    }
    q.push(v);

}

void DFS(int v) {
    COLOR[v] = 1;
    for (int i = 0; i < G[v].size(); i++) {
        if (COLOR[G[v][i]] == 0) {
            DFS(G[v][i]);
        }
    }
    ans[v] = k;

}

int main() {
    freopen("condense.in", "r", stdin);
    freopen("condense.out", "w", stdout);

    cin >> n >> m;
    g.resize(n + 10);
    G.resize(n + 10);
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        G[v2].push_back(v1);


    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0)
            dfs(i);
    }
    cerr << G[1].size() << endl;
    while (!q.empty()) {

        v = q.top();
        q.pop();
        if (COLOR[v] == 0) {
            cerr << v << ' ';
            DFS(v);
            k++;

        }

    }
    cout << k - 1 << endl;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';


    return 0;
}