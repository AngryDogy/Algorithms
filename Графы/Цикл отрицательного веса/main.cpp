#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
vector <vector<pair < ll, ll>>>
g;
vector <vector<pair < int, int>>>
number;
const ll inf = 1e9;
const ll minusinf = -1e9;
const int size = 1e4;
const int size2 = 1e5 + 10;
int n, m, v1, v2, p, ch = 0, v, begin, t = 0, ansize;
ll ford[size];
int color[size], ans[size2], parents[size], edge[size2], timee[size];
bool out = 0;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 5);
    number.resize(n + 5);
    for (int i = 1; i <= m; i++) {
        cin >> v1 >> v2 >> p;
        g[v1].push_back(make_pair(v2, p));
        number[v1].push_back(make_pair(v2, i));
    }

    for (int k = 0; k <= n - 1; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < g[i].size(); j++) {
                if (ford[g[i][j].first] > ford[i] + g[i][j].second) {
                    ford[g[i][j].first] = ford[i] + g[i][j].second;
                    parents[g[i][j].first] = i;
                    edge[g[i][j].first] = number[i][j].second;
                    //ford[g[i][j].first]=max(minusinf, ford[g[i][j].first]);

                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            if (ford[g[i][j].first] > ford[i] + g[i][j].second) {
                v = i;
                if (parents[v] == v) {
                    ans[ch] = edge[v];
                    ch++;
                    ansize = ch;
                    out = 1;
                    break;
                }
                while (color[parents[v]] == 0) {
                    color[v] = 1;
                    timee[v] = t;
                    t++;
                    ans[ch] = edge[v];
                    ch++;
                    v = parents[v];

                }
                ans[ch] = edge[v];
                ch++;
                v = parents[v];
                ansize = ch - timee[v];
                out = 1;
                break;

            }
        }
        if (out)
            break;
    }
    if (out) {
        cout << "YES" << endl;
        cout << ansize << endl;
        for (int i = ch - 1; i >= timee[v]; i--)
            cout << ans[i] << ' ';

    } else
        cout << "NO";
    return 0;
}