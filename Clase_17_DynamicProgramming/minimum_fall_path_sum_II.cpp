#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vvi dp(n, vi(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0) {
                dp[i][j] = grid[i][j];
            }
            else {
                int minim = INT_MAX;
                for (int k = 0; k < m; k++) {
                    if (k == j) continue;
                    minim = min(minim, dp[i - 1][k]);
                }
                dp[i][j] = minim + grid[i][j];
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < m; i++) {
        ans = min(ans, dp[n - 1][i]);
    }
    return ans;
}

int main(int argc, char const* argv[]){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> grid = {{1,2,3},
                                {4,5,6},
                                {7,8,9} };
    cout << minFallingPathSum(grid) << "\n";
    return 0;
}