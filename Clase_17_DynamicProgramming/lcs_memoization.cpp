#include <iostream>
#include <vector>
#include <string>

using namespace std;

int lcs_aux(string P0, string Q0, int m, int n, vector<vector<int>>& memo) {
    if (m == 0 || n == 0)
        return 0;
    if (memo[m][n])
        return memo[m][n];
    if (P0[m - 1] == Q0[n - 1])
        return 1 + lcs_aux(P0, Q0, m - 1, n - 1, memo);
    else
        return max(lcs_aux(P0, Q0, m, n - 1, memo), lcs_aux(P0, Q0, m - 1, n, memo));
}

int lcs_mem(string P0, string Q0) {
    int m = P0.size();
    int n = Q0.size();
    vector<vector<int>> lcs_mem(m + 1, vector<int>(n + 1, 0));
    return lcs_aux(P0, Q0, m, n, lcs_mem);
}

int main(int argc, char const* argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1 = "abcdefghij";
    string s2 = "ecdgi";

    cout << lcs_mem(s1, s2) << endl;

    return 0;
}