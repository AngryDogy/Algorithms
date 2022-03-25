#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
const int size = 1e6;
vector <vector<pair < int, int>>>
g;
/*struct edge
{
   int s, f, w;
   edge(){}
   vect(int _s, int _f, int _w)
   {
   		s=_s;
   		f=_f;
   		w=_w;
   }
   bool operator <(edge a)
   {
   		return w<a.w;
   }
};*/
set <pair<int, int>> q;
int n, m, v1, v2, p, k = 0, v, w;
int color[size];
long long ans = 0;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    g.resize(n + 10);
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2 >> p;
        g[v1].push_back(make_pair(v2, p));
        g[v2].push_back(make_pair(v1, p));
        if (v1 == 1) {
            q.insert(make_pair(p, v2));
            continue;
        }
        if (v2 == 1) {
            q.insert(make_pair(p, v1));
            continue;
        }
    }
    color[1] = 1;
    while (k < n - 1) {
        while (1) {
            auto it = q.begin();
            if (color[it->second] == 0)
                break;
            q.erase(it);
        }
        auto it = q.begin();
        v = it->second;
        w = it->first;
        ans = ans + w;
        q.erase(it);
        color[v] = 1;
        for (int i = 0; i < g[v].size(); i++) {
            if (color[g[v][i].first] == 0) {
                q.insert(make_pair(g[v][i].second, g[v][i].first));
            }
        }
        k++;
    }
    cout << ans;
    return 0;
}