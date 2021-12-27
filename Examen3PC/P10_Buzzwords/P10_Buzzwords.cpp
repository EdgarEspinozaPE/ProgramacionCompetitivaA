/*
Link P10: https://open.kattis.com/problems/buzzwords
*/

#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long int ll;
typedef vector<ll> vll;

const ll limit = 1e5 + 5;
ll n = 0, t = 0;
deque<int> lcp;
ll tmp[limit], pos[limit];

bool compare(ll i, ll j) {
    if (pos[i] != pos[j]) 
        return (pos[i] < pos[j]);
    i += t;
    j += t;
    if (i < n && j < n) 
        return (pos[i] < pos[j]);
    return (i > j);
}

vll SuffixArray(string& str) {
    vll sa(n);
    for (ll i = 0; i < n; i++) {
        sa[i] = i;
        pos[i] = str[i];
    }
    for (t = 1; t < 2 * n + 1; t *= 2) {
        sort(sa.begin(), sa.end(), compare);
        for (ll i = 0; i < n - 1; i++) {
            tmp[i + 1] = tmp[i];
            if (compare(sa[i], sa[i + 1])) tmp[i + 1]++;
        }
        for (ll i = 0; i < n; i++) {
            pos[sa[i]] = tmp[i];
        }
        if (tmp[n - 1] == n - 1) break;
    }
    return sa;
}

void find_lcp(string& str,vll& sa ) {
    ll p = 0;
    lcp.assign(n, 0);
    for (ll i = 0; i < n; i++) {
        if (pos[i] != n - 1) {
            ll j = sa[pos[i] + 1];
            while (str[i + p] == str[j + p])p++;
            lcp[pos[i]] = p;
            if (p > 0) p--;
        }
    }
    int tp = lcp[n - 1];
    lcp.push_front(tp);
    lcp.pop_back();
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;

    while (getline(cin, str)) {
        if (str == "") break;
        str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
        n = str.size();
        
        vll sa(n);
        ll ans;
        sa = SuffixArray(str);
        find_lcp(str,sa);

        for (int i = 1; i <= n; i++) {
            t = 0;
            ans = 0;
            for (int j = 0; j < n; j++) {
                if (lcp[j] >= i) {
                    t++;
                    ans = max(ans, t);
                }
                else 
                    t = 0;
            }
            if (ans >= 1)
                cout << ans + 1 << "\n";
            else 
                break;
        }
        cout << "\n";
    }
    return 0;
}