#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

#define INF 9999

using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<pair<int, int>> spii;

int i, j, k;
int rows, cols;

int main(int argc, char const* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> rows >> cols;

    vvi offsets = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    vvi grid(rows + 2, vector<int>(cols + 2, 0));
    vvi grid2(rows + 2, vector<int>(cols + 2, 0));
    spii trees;
    spii trees2;

    char temp;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> temp;
            if (temp == 'T') {
                grid[i + 1][j + 1] = INF;
                trees.insert(make_pair(i + 1, j + 1));
            }
        }
    }

    //usar bfs

    int colorAux = -1;
    while (trees.size())
    {
        trees2 = trees;
        grid2 = grid;
        auto itr = trees2.begin();
        while (itr != trees2.end()) {
            int color = INF;
            for (int i = 0; i < 4; i++)
            {
                int xx = (*itr).first + offsets[i][0];
                int yy = (*itr).second + offsets[i][1];
                if (xx < rows + 2 && xx >= 0 && yy < cols + 2 && yy >= 0) {
                    if (grid2[xx][yy] < color)
                        color = grid2[xx][yy];
                }
            }
            if (color < INF) {
                grid[(*itr).first][(*itr).second] = color + 1;
                trees.erase((*itr));
                if (colorAux < color + 1)
                    colorAux = color + 1;
            }
            itr++;
        }
    }

    for (int i = 1; i < rows + 1; i++) {
        for (int j = 1; j < cols + 1; j++) {
            if (colorAux >= 10)
                cout << ".";
            if (grid[i][j] == 0)
                cout << "..";
            else if (grid[i][j] < 10)
                cout << "." << grid[i][j];
            else
                cout << grid[i][j];
        }
        cout << "\n";
    }
    return 0;
}