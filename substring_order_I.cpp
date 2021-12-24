#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll mxn = 1e5 + 5;
ll sa[mxn], pos[mxn], tmp[mxn], lcp[mxn];
ll gap, n;
string s;

bool comp(ll x, ll y) {
    if (pos[x] != pos[y])
        return pos[x] < pos[y];
    x += gap;
    y += gap;
    return (x < n && y < n) ? pos[x] < pos[y] : x > y;
}

void suffix() {
    for (ll i = 0; i < n; i++)
        sa[i] = i, pos[i] = s[i];

    for (gap = 1;; gap <<= 1) {
        sort(sa, sa + n, comp);
        for (ll i = 0; i < n - 1; i++)
            tmp[i + 1] = tmp[i] + comp(sa[i], sa[i + 1]);
        for (ll i = 0; i < n; i++)
            pos[sa[i]] = tmp[i];
        if (tmp[n - 1] == n - 1)
            break;
    }
}

void build_lcp() {
    for (ll i = 0, k = 0; i < n; i++) if (pos[i] != n - 1) {
        ll j = sa[pos[i] + 1];
        while (s[i + k] == s[j + k])
            k++;
        lcp[pos[i]] = k;
        if (k) k--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s; n = s.size();
    suffix();
    build_lcp();
    ll k; 
    cin >> k;
    ll prev = 0;
    ll act = 0;
    for (ll i = 0; i < n; i++) {
        if (act + (n - sa[i]) - prev >= k) {
            ll j = prev;
            string ans = s.substr(sa[i], j);
            while (act < k) {
                ans += s[sa[i] + j];
                act++;
                j++;
            }
            cout << ans;
            return 0;
        }
        act += (n - sa[i]) - prev;
        prev = lcp[i];
    }
    return 0;
}


