#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

void dfs(vii& grid, int i, int j, int m, int n) {
    if (i < 0 || i >(m - 1) || j < 0 || j >(n - 1) || grid[i][j] != 1) return;


    if (grid[i][j] == 1) {

        grid[i][j] = 0;
        int rowNbr[] = { -1, 0, 0, 1 };
        int colNbr[] = { 0, -1, 1, 0 };
        for (int k = 0; k < 4; k++) {
            int row = i + rowNbr[k];
            int col = j + colNbr[k];
            dfs(grid, row, col, m, n);
        }
    }

}


int countingStars(vii& grid, int m, int n) {
    int res = 0;
    int rowNbr[] = { -1, 0, 0, 1 };
    int colNbr[] = { 0, -1, 1, 0 };

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
                res++;
                for (int k = 0; k < 4; k++) {
                    int row = i + rowNbr[k];
                    int col = j + colNbr[k];
                    dfs(grid, row, col, m, n);
                }
            }

    return res;
}

int main(int argc, char const* argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, tc = 1;
    while (true) {
        cin >> m >> n;
        if (cin.eof()) break;

        vii grid(m, vi(n));

        string lineStr;
        for (int i = 0; i < m; i++) {
            cin >> lineStr;
            int j = 0;
            for (auto car : lineStr) {
                grid[i][j++] = (car == '#') ? 0 : 1;
            }
        }
        cout << "case " << tc << ": " << countingStars(grid, m, n) << "\n";
        tc++;
    }


    return 0;
}