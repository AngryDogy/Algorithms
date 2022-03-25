#include<iostream>

using namespace std;


long long w, n, m, p;
long long dp[400][11000];

int main() {
    freopen("knapsack.in", "r", stdin);
    freopen("knapsack.out", "w", stdout);
    cin >> w >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p;
        for (int j = 1; j <= w; j++) {
            if (j - p >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - p] + p);
            else
                dp[i][j] = dp[i - 1][j];
        }


    }
    cout << dp[n][w];
    return 0;
}