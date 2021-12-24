#include<iostream>
#include<vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long  ll;

const ll mxN = 1e5 + 5;
ll sa[mxN], pos[mxN], tmp[mxN], lcp[mxN];
ll gap, N;
string S;

bool comp(ll x, ll y) {
    if (pos[x] != pos[y])
        return pos[x] < pos[y];
    x += gap;
    y += gap;
    return (x < N&& y < N) ? pos[x] < pos[y] : x > y;
}

void suffix() {
    for (ll i = 0; i < N; i++)
        sa[i] = i, pos[i] = S[i];

    for (gap = 1;; gap <<= 1) {
        sort(sa, sa + N, comp);
        for (ll i = 0; i < N - 1; i++)
            tmp[i + 1] = tmp[i] + comp(sa[i], sa[i + 1]);
        for (ll i = 0; i < N; i++)
            pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1)
            break;
    }
}

void build_lcp() {
    for (ll i = 0, k = 0; i < N; i++) if (pos[i] != N - 1) {
        ll j = sa[pos[i] + 1];
        while (S[i + k] == S[j + k])
            k++;
        lcp[pos[i]] = k;
        if (k) k--;
    }
}

ll pre[mxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S; N = S.size();
    suffix();
    build_lcp();
    ll prev = 0;
    for (ll i = 0; i < N; i++) {
        pre[prev + 1]++;
        pre[N - sa[i] + 1]--;
        prev = lcp[i];
    }
    for (ll i = 1; i <= N; i++) {
        cout << pre[i] << ' ';
        pre[i + 1] += pre[i];
    }
    return 0;
}
