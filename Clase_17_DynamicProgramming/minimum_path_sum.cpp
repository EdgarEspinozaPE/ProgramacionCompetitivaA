#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int minPathSum(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> memo(rows, vector<int>(cols, 0));
    int i, j;
    memo[0][0] = grid[0][0];

    for (i = 1; i < rows; i++) {
        memo[i][0] = memo[i - 1][0] + grid[i][0];
    }

    for (j = 1; j < cols; j++) {
        memo[0][j] = memo[0][j - 1] + grid[0][j];
    }

    for (i = 1; i < rows; i++)
        for (j = 1; j < cols; j++) {
            memo[i][j] = min(memo[i - 1][j], memo[i][j - 1]) + grid[i][j];
        }
    return memo[rows - 1][cols - 1];
}

int main(int argc, char const* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> grid = { {1,3,1},
                                {1,5,1},
                                {4,2,1} };
    cout << minPathSum(grid) << endl;
    return 0;
}