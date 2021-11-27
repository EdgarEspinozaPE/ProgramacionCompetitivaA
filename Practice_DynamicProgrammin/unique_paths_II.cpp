#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;


int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();

    vvi dp(n, vi(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            }
            else if (i == 0 && j == 0) {
                dp[i][j] = 1;
            }
            else if (i == 0) {
                dp[i][j] = dp[i][j - 1];
            }
            else if (j == 0) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[n - 1][m - 1];
}

int main(int argc, char const* argv[]){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    vvi obstacleGrid = { {0,0,0},
                         {0,1,0},
                         {0,0,0} };
    cout << uniquePathsWithObstacles(obstacleGrid) << "\n";
    return 0;
}