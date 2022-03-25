#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int size = 1e6 + 1e4;


int n, val;
vector<int> a;
vector<int> d;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    a.resize(n + 10);
    d.resize(n + 10);

    for (int i = 0; i < n; i++) {
        cin >> a[i];

    }
    fill(d.begin(), d.end(), size);
    d[0] = -size;
    for (int i = 0; i < n; i++) {
        int j = int(upper_bound(d.begin(), d.end(), a[i]) - d.begin());
        if (d[j - 1] <= a[i] && a[i] <= d[j])
            d[j] = a[i];

    }
    for (int i = n; i >= 0; i--) {
        if (d[i] != size) {
            cout << i;
            break;
        }
    }


    return 0;
}