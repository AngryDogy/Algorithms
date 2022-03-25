#include<bits/stdc++.h>

using namespace std;
const int minusinf = -1e6;
const int size = 1e5;
vector <vector<int>> g;
int n, v1, v2, r, mx, v, w, to, ch = 0;
int ans[size];
multimap<int, int> s;

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    g.resize(n + 10);
    for (int i = 0; i < n - 1; i++) {

        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    for (int i = 1; i <= n; i++) {
        queue<int> q;
        int was[n + 10] = {};
        int r[n + 10] = {};
        q.push(i);
        r[i] = 0;
        was[i] = 1;
        mx = minusinf;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int j = 0; j < g[v].size(); j++) {
                if (was[g[v][j]] == 0) {
                    was[g[v][j]] = 1;
                    q.push(g[v][j]);
                    r[g[v][j]] = r[v] + 1;
                    mx = max(mx, r[g[v][j]]);
                }
            }
        }

        s.insert(make_pair(mx, i));

    }
    while (1) {
        auto it = s.begin();
        v = it->second;
        w = it->first;
        s.erase(it);
        ans[ch] = v;
        ch++;
        auto next = s.begin();
        to = next->first;

        if (to == w)
            continue;
        else
            break;

    }
    sort(ans, ans + ch);
    cout << ch << endl;
    for (int i = 0; i < ch; i++)
        cout << ans[i] << ' ';


    return 0;
}