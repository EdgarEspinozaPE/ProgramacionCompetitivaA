#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;

int dp[501][501];

int solve(int a, int b) {
    if (a > b)   
        swap(a, b);

    if (dp[a][b] != INF)     
        return dp[a][b];

    
    if (a == 1 || b == 1) {
        if (a == 1) {
            dp[a][b] = b - 1;
            return dp[a][b];
        }
        else {
            dp[a][b] = a - 1;
            return dp[a][b];
        }
    }

    if (a == b)              
        return dp[a][b] = 0;

    for (int i = 1; i < b; i++)
        dp[a][b] = min(dp[a][b], solve(a, i) + solve(a, b - i) + 1);

    for (int i = 1; i < a; i++)
        dp[a][b] = min(dp[a][b], solve(i, b) + solve(a - i, b) + 1);

    return dp[a][b];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0x3f, sizeof(dp));
    int A, B;
    cin >> A >> B;
    cout << solve(A, B);
}