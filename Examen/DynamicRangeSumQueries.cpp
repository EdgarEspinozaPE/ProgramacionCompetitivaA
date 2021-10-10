#include <iostream>
using namespace std;

int N, Q, t, a, b;
long long x[200000 + 1], ds[200000 + 1];

void update(int idx, long long val) {
    long long diff = val - x[idx];
    for (int i = idx; i <= N; i += -i & i)
        ds[i] += diff;
    x[idx] = val;
}

long long query(int idx) {
    long long sum = 0;
    for (int i = idx; i > 0; i -= -i & i)
        sum += ds[i];
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin>>x[0];
        update(i, x[0]);
    }
    for (int q = 0; q < Q; q++) {
        cin >> t >> a >> b;
        if (t == 1)  update(a, b);
        else
            cout << query(b) - query(a - 1)<<"\n";
    }
}