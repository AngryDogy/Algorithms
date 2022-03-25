#include<bits/stdc++.h>

using namespace std;
const int size = 1e6;
vector <vector<int>> g;
int n, m, v1, v2, start, k = 0, ch = 0;
int in[size], ans[size];
vector<int> points;

int lans(int val) {
    if (val < 0)
        return -val;
    else
        return val;
}

void dfs(int v) {
    while (g[v].size() != 0) {

        int to = g[v][0];
        auto it = g[v].begin();
        g[v].erase(it);
        k++;
        dfs(to);
    }
    ans[ch] = v;
    ch++;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    g.resize(n + 10);
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        in[v2]++;
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] != g[i].size()) {
            points.push_back(i);
        }
    }
    if (points.size() > 2 || points.size() == 1) {
        cout << "No solution";
        return 0;
    }
    start = -1;
    if (points.size() == 2) {
        if (labs(in[points[0]] - g[points[0]].size()) == 1 && lans(in[points[1]] - g[points[1]].size()) == 1) {
            int check = in[points[0]] - g[points[0]].size();
            if (check < 0) {

                start = points[0];
                //g[points[0]].push_back(points[1]);

            } else {
                start = points[1];
                //g[points[1]].push_back(points[0]);
            }

        } else {
            cout << "No solution";
            return 0;
        }

    }

    if (start == -1) {
        start = 1;
        while (g[start].size() == 0)
            start++;
    }
    dfs(start);
    if (k != m) {
        cout << "No solution";
    } else {
        cout << "Solution exists" << endl;
        for (int i = ch - 1; i >= 0; i--)
            cout << ans[i] << ' ';
    }


    return 0;
}