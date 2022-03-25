#include<iostream>
#include<algorithm>

using namespace std;
int INF = -1000000000;
int A[300001], N, n = 1, V1, V2;

void pushup(int v) {
    if (A[v] > A[v / 2]) {
        swap(A[v], A[v / 2]);
        pushup(v / 2);
    }
    return;

}

void pushdown(int v) {
    if (2 * v >= n) {
        return;
    }
    if (A[v] < A[2 * v] || A[v] < A[2 * v + 1]) {

        if (A[2 * v] > A[2 * v + 1]) {
            swap(A[2 * v], A[v]);
            pushdown(2 * v);
        } else {
            swap(A[2 * v + 1], A[v]);
            pushdown(2 * v + 1);

        }
        return;
    }
}

void bye() {
    cout << A[1] << endl;
    A[1] = A[n - 1];
    A[n - 1] = INF;
    n--;
    pushdown(1);
    return;
}

int main() {
    freopen("heap.in", "r", stdin);
    freopen("heap.out", "w", stdout);
    cin >> N;
    fill(A, A + N + 1, INF);
    A[0] = -INF;
    for (int i = 0; i < N; i++) {
        cin >> V1;
        if (V1 == 0) {
            cin >> V2;
            A[n] = V2;
            pushup(n);
            n++;

        } else {
            bye();
        }
    }
    return 0;
}