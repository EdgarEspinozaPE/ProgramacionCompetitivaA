#include<iostream>
#include<vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

const long long int limi = 1e5 + 5;
int n = 0, t = 0, ans = 0;
string msg;
int sa[limi], lcp[limi];
int tmp[limi], pos[limi];

bool comparar(int i, int j) {
    if (pos[i] != pos[j]) return (pos[i] < pos[j]);
    i += t;
    j += t;
    if (i < n && j < n) return (pos[i] < pos[j]);
    return (i > j);
}

void suffixArray() {
    for (int i = 0; i < n; i++) {
        sa[i] = i;
        pos[i] = msg[i];
    }
    for (t = 1; t < 2 * n + 1; t *= 2) {
        sort(sa, sa + n, comparar);
        for (int i = 0; i < n - 1; i++) {
            tmp[i + 1] = tmp[i];
            if (comparar(sa[i], sa[i + 1])) tmp[i + 1]++;
        }
        for (int i = 0; i < n; i++) {
            pos[sa[i]] = tmp[i];
        }
        if (tmp[n - 1] == n - 1) break;
    }
}

void find_lcp() {
    int p = 0;
    for (int i = 0; i < n; i++) {
        if (pos[i] != n - 1) {
            int j = sa[pos[i] + 1];
            while (msg[i + p] == msg[j + p])p++;
            lcp[pos[i]] = p;
            if (p > ans) ans = p;
            if (p > 0) p--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin >> x;
    cin >> msg;
    n = msg.length();
    suffixArray();
    find_lcp();

    cout << ans << "\n";
    return 0;
}