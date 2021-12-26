#include <iostream>
#include <cstring>

using namespace std;

const int N = 100000;
typedef long long int ll;

ll r[N + 1], q[N + 1], a[N];

void update(ll* t, ll i, ll dt, ll n) {
	for (; i <= n; t[i] += dt, i += ((i) & (~(i)+1)));
}

ll prefixsum(ll* t, ll i) {
	ll w = 0;
	for (; i; w += t[i], i -= ((i) & (~(i)+1)));
	return w;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int j, k;
	ll K, ts, cs, ans, n;
	cin >> n;

	memset(r, 0, sizeof(r));
	memset(q, 0, sizeof(q));

	for (K = 0; (1UL << K) < n; ++K);

	for (j = 0; j < n; ++j) {
		cin >> a[j];
		update(q, j + 1, prefixsum(r, n) - prefixsum(r, a[j]),n);
		update(r, a[j], 1,n);
	}

	memset(r, 0, sizeof(r));

	for (ans = 0, k = 0; k < n; ++k) {
		ans += prefixsum(r, n) - prefixsum(r, a[k]);
		update(r, a[k], prefixsum(q, k + 1) - prefixsum(q, k),n);
	}

	cout << ans << "\n";
	return 0;
}