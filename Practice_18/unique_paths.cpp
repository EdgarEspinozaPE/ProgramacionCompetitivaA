#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int uniquePaths(int m, int n) {
    vii paths(m, vi(n, 0));
    for (int i = 0; i < m; i++) {
        paths[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        paths[0][i] = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
        }
    }
    return paths[m - 1][n - 1];
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m = 3;
    int n = 7;
    cout << uniquePaths(m, n) << "\n";

    return 0;
}