#include <iostream>

using namespace std;

typedef pair<int, int> pii;
const int MAX = 20;
const int INF = 21;




int main() {
    pii dp[1 << 20];
    int N;
    long long  X, w[MAX];
    cin >> N >> X;
    for (int i = 0; i < N; i++) 
        cin >> w[i];
        

    dp[0] = { 1, 0 };
    for (int mask = 1; mask < (1 << N); mask++) {
        dp[mask] = { INF, 0 };
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                pii can = dp[mask ^ (1 << i)];
                if (can.second + w[i] <= X) {
                    can.second += w[i];
                }
                else {
                    can.first++;
                    can.second = w[i];
                }
                dp[mask] = min(dp[mask], can);
            }
        }
    }

    cout << dp[(1 << N) - 1].first << "\n";
}