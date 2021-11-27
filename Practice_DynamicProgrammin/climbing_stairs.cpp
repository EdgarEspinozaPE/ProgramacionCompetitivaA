#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;


int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main(int argc, char const* argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    cout << climbStairs(2) << "\n";
    return 0;
}