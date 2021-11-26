#include <iostream>
#include <vector>
#include <string>

using namespace std;

int lcs(string P0, string Q0, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (P0[m - 1] == Q0[n - 1])
        return 1 + lcs(P0, Q0, m - 1, n - 1);
    else
        return max(lcs(P0, Q0, m, n - 1), lcs(P0, Q0, m - 1, n));
}

int main(int argc, char const* argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1 = "abcdefghij";
    string s2 = "ecdgi";

    cout << lcs(s1, s2, s1.size(), s2.size()) << "\n";

    return 0;
}