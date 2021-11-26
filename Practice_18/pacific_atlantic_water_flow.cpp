#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

void dfs(vii image, int sr, int sc, map<pair<int, int>, int>& vis, int oldColor) {
    if (vis[{sr, sc}] == 1 || sr < 0 || sr >= image.size() || sc < 0 || sc >= image[sr].size() || image[sr][sc] < oldColor) {
        return;
    }

    vis[{sr, sc}] = 1;
    dfs(image, sr + 1, sc, vis, image[sr][sc]);
    dfs(image, sr - 1, sc, vis, image[sr][sc]);
    dfs(image, sr, sc + 1, vis, image[sr][sc]);
    dfs(image, sr, sc - 1, vis, image[sr][sc]);
}

vii pacificAtlantic(vii& heights) {
    int m = heights.size();
    int n = heights[0].size();
    map<pair<int, int>, int> pacif;
    map<pair<int, int>, int> atlan;

    for (int i = 0; i < m; i++) {
        dfs(heights, i, 0, pacif, heights[i][0]);
        dfs(heights, i, n - 1, atlan, heights[i][n - 1]);
    }

    for (int i = 0; i < n; i++) {
        dfs(heights, 0, i, pacif, heights[0][i]);
        dfs(heights, m - 1, i, atlan, heights[m - 1][i]);
    }

    vii out;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pacif[{i, j}] == 1 && atlan[{i, j}] == 1) {
                out.push_back({ i,j });
            }
        }
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vii heights = { {1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4} };
    vii res = pacificAtlantic(heights);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;

}