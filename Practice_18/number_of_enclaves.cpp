#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int dfs(vii& image, int r1, int s1, bool& find) {
    if (r1 < 0 || r1 >= image.size() || s1 < 0 || s1 >= image[r1].size()) {
        find = true;
        return 0;
    }
    else if (image[r1][s1] != 1) {
        return 0;
    }

    image[r1][s1] = 0;
    int cont = 1;
    cont += dfs(image, r1 + 1, s1, find);
    cont += dfs(image, r1 - 1, s1, find);
    cont += dfs(image, r1, s1 + 1, find);
    cont += dfs(image, r1, s1 - 1, find);

    return cont;
}

int numEnclaves(vii& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int sum = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            bool flag = false;
            if (grid[i][j] == 1) {
                int altsum = dfs(grid, i, j, flag);
                if (flag == false) sum += altsum;
            }
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vii grid = { {0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0} };
    cout << numEnclaves(grid) << "\n";

    return 0;
}