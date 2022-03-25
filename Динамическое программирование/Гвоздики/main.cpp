#include<iostream>
#include<algorithm>

using namespace std;
const int inf = 1000000000;
int a[1000], dp[150][150];

int main() {
    freopen("nails.in", "r", stdin);
    freopen("nails.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        dp[i][0] = inf;
        dp[i][1] = inf;
    }
    dp[0][0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = min(dp[i - 1][0] + (a[i] - a[i - 1]), dp[i - 1][1] + (a[i] - a[i - 1]));
    }
    int ans = dp[n - 1][1];
    cout << ans;


    return 0;
}