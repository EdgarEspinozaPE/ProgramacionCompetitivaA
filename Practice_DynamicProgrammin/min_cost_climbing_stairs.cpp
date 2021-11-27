#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;


int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int m = cost[0];
    vi dp(n, 0);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    return min(dp[n - 1], dp[n - 2]);
}

int main(int argc, char const* argv[]){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi cost = { 10, 15, 20 };
    cout << minCostClimbingStairs(cost) << "\n";
    return 0;
}