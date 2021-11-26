#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int m, n;
const int LV = 8;

static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void dfs(vii& grid, int r, int c, vii& visited) {
    if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] == 1) return;
    visited[r][c] = 1;
    for (int i = 0; i < LV; i++) {
        int nr = r + rowNbr[i];
        int nc = c + colNbr[i];
        if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
            dfs(grid, nr, nc, visited);
        }
    }
}

int shebasAmebas(vii& grid) {
    vii visited(m, vi(n, 0));

    int res = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 0 && grid[i][j] != 0) {
                dfs(grid, i, j, visited);
                res++;
            }
        }
    }
    return res;
}

int main(int argc, char const* argv[]){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    string lineStr;
    vii grid(m, vi(n));
    for (int i = 0; i < m; i++) {
        cin >> lineStr;
        int j = 0;
        for (auto car : lineStr) {
            grid[i][j++] = (car == '#') ? 1 : 0;
        }
    }

    cout << shebasAmebas(grid) << "\n";

    return 0;
}