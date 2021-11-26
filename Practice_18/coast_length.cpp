#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& image, int r1, int s1) {
    if (r1 < 0 || r1 >= image.size() || s1 < 0 || s1 >= image[r1].size() || image[r1][s1] != 0) {
        return 0;
    }

    image[r1][s1] = 2;
    int cont = 0;
    if (r1 < image.size() - 1 && image[r1 + 1][s1] == 1) {
        cont++;
    }
    if (r1 > 0 && image[r1 - 1][s1] == 1) {
        cont++;
    }
    if (s1 < image[r1].size() - 1 && image[r1][s1 + 1] == 1) {
        cont++;
    }
    if (s1 > 0 && image[r1][s1 - 1] == 1) {
        cont++;
    }

    cont += dfs(image, r1 + 1, s1);
    cont += dfs(image, r1 - 1, s1);
    cont += dfs(image, r1, s1 + 1);
    cont += dfs(image, r1, s1 - 1);

    return cont;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m = 0, n = 0;
    char a;
    cin >> m >> n;
    int cont = 0;
    vector<vector<int>>cost(m + 2, vector<int>(n + 2, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a;
            cost[i][j] = a - '0';
        }
    }

    cout << dfs(cost, 0, 0) << "\n";
}