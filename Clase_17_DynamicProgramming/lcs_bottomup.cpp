#include <iostream>
#include <vector>
#include <string>

using namespace std;

int lcs_bu(string P0, string Q0, int m, int n) {
    vector<vector<int>> lcs_mem(m + 1, vector<int>(n + 1, 0));
    int i, j;
    for (i = 0; i <= m; ++i)
        for (j = 0; j <= n; ++j)
            if (i == 0 || j == 0)
                lcs_mem[i][j] = 0;
            else if (P0[i - 1] == Q0[j - 1])
                lcs_mem[i][j] = 1 + lcs_mem[i - 1][j - 1];
            else
                lcs_mem[i][j] = max(lcs_mem[i][j - 1], lcs_mem[i - 1][j]);
    return lcs_mem[m][n];
}

int main(int argc, char const* argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1 = "abcdefghij";
    string s2 = "ecdgi";

    cout << lcs_bu(s1, s2, s1.size(), s2.size()) << endl;


    return 0;
}