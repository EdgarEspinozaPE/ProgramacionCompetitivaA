#include <iostream>
#include <algorithm>
#include <math.h>

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
    return (x < n&& y < n) ? pos[x] < pos[y] : x > y;
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

pair<ll, ll> seg[mxn * 10];
ll mark[mxn * 10];

void push(ll k) {
    if (mark[k]) {
        mark[k] = 0;
        seg[2 * k].first = seg[2 * k + 1].first = seg[k].first / 2;
        seg[2 * k].second = seg[2 * k + 1].second = 0;
        mark[2 * k] = mark[2 * k + 1] = 1;
    }
}

void update(ll v, ll a, ll b, ll k, ll x, ll y) {
    if (b < x || a > y) 
        return;
    if (a <= x && b >= y) {
        seg[k].second += v;
        return;
    }
    ll h = min(b, y) - max(a, x) + 1;
    push(k);
    seg[k].first += h * v;
    ll d = (x + y) / 2;
    update(v, a, b, 2 * k, x, d);
    update(v, a, b, 2 * k + 1, d + 1, y);
}
ll assign(ll v, ll a, ll b, ll k, ll x, ll y) {
    if (b < x || a > y) 
        return seg[k].first + (y - x + 1) * seg[k].second;
    if (a <= x && b >= y) {
        seg[k].first = (y - x + 1) * v;
        seg[k].second = 0;
        mark[k] = 1;
        return seg[k].first;
    }
    push(k);
    ll d = (x + y) / 2;
    seg[2 * k].second += seg[k].second, seg[2 * k + 1].second += seg[k].second;
    seg[k].second = 0;
    seg[k].first = assign(v, a, b, 2 * k, x, d) + assign(v, a, b, 2 * k + 1, d + 1, y);
    return seg[k].first;

}
ll sum(ll a, ll b, ll k, ll x, ll y) {
    if (b < x || a > y) 
        return 0;
    if (a <= x && b >= y) {
        return seg[k].first + (y - x + 1) * seg[k].second;
    }
    push(k);
    seg[k].first += (y - x + 1) * seg[k].second;
    seg[2 * k].second += seg[k].second, seg[2 * k + 1].second += seg[k].second;
    seg[k].second = 0;
    ll d = (x + y) / 2;
    return sum(a, b, 2 * k, x, d) + sum(a, b, 2 * k + 1, d + 1, y);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s; n = s.size();
    suffix();
    build_lcp();
    ll k; cin >> k;

    k = n * (n + 1) / 2 - k + 1;
    ll K = 1 << (ll)ceil(log2(n + 1));
    ll cur = 0;
    for (ll i = n - 1; i >= 0; i--) {
        update(1, 1, n - sa[i], 1, 0, K - 1);
        ll prev = (i ? lcp[i - 1] : 0);
        ll l = prev + 1, r = n - sa[i];
        ll ans = -1;
        while (l <= r) {
            ll m = l + (r - l) / 2;
            if (cur + sum(m, n - sa[i], 1, 0, K - 1) >= k) {
                ans = m; l = m + 1;
            }
            else r = m - 1;
        }
        if (ans != -1) {
            cout << s.substr(sa[i], ans);
            return 0;
        }
        cur += sum(prev + 1, n - sa[i], 1, 0, K - 1);
        assign(0, prev + 1, n - sa[i], 1, 0, K - 1);
    }
    return 0;
}


