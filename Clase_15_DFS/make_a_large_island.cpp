#include <iostream>
#include <vector>
#include <map>

using namespace std;

int dfs(vector<vector<int>>& grid, int i, int j, int color) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] != 1)
        return 0;
    grid[i][j] = color;
    int cont = 1;
    cont += dfs(grid, i + 1, j, color);
    cont += dfs(grid, i - 1, j, color);
    cont += dfs(grid, i, j + 1, color);
    cont += dfs(grid, i, j - 1, color);
    return cont;
}

int largestIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    bool zero = false;
    vector<int> areas(m * m + 2, 0);
    int color = 2;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                areas[color] = dfs(grid, i, j, color);
                color++;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                zero = true;
                map<int, int> newArea;
                if (i > 0) newArea[grid[i - 1][j]] = grid[i - 1][j];
                if (j > 0) newArea[grid[i][j - 1]] = grid[i][j - 1];
                if (i < m - 1) newArea[grid[i + 1][j]] = grid[i + 1][j];
                if (j < m - 1) newArea[grid[i][j + 1]] = grid[i][j + 1];

                int temp = 0;
                for (map<int, int>::iterator it = newArea.begin(); it != newArea.end(); ++it) {
                    int op = it->second;
                    temp += areas[op];
                }
                ans = max(temp, ans);
            }

        }
    }
    if (zero == false) {
        return m * m;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> island = { {0,0,1,0,0,0,0,1,0,0,0,0,0},
                                   {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                   {0,1,1,0,1,0,0,1,0,0,0,0,0},
                                   {0,1,0,0,0,1,0,0,1,0,1,0,0},
                                   {0,1,0,0,1,0,0,0,1,1,1,0,0},
                                   {0,1,1,0,0,0,0,0,0,0,1,0,0},
                                   {0,0,1,0,1,1,0,1,1,1,0,0,0},
                                   {0,0,1,0,0,0,0,1,1,0,0,0,0} };

    cout << largestIsland(island);
    return 0;
}