/*
Link P2: https://open.kattis.com/problems/suffixsorting
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll n = 0, t = 0;
vll pos(100001);

bool cmp(ll i, ll j) {
	if (pos[i] != pos[j])
		return (pos[i] < pos[j]);
	i += t;
	j += t;
	if (i < n && j < n)
		return (pos[i] < pos[j]);
	return (i > j);
}

vll constructSA(const string txt) {

	vll SA(n);
	vll temp(100001);

	for (ll i = 0; i < n; i++) {
		SA[i] = i;
		pos[i] = txt[i];
	}
	for (t = 1; t < 2 * n + 1; t *= 2) {
		sort(SA.begin(), SA.end(), cmp);
		for (ll i = 0; i < n - 1; i++) {
			temp[i + 1] = temp[i];
			if (cmp(SA[i], SA[i + 1])) temp[i + 1]++;
		}
		for (ll i = 0; i < n; i++) {
			pos[SA[i]] = temp[i];
		}
		if (temp[n - 1] == n - 1) 
			break;
	}
	return SA;
}

void suffixsorting(const string& str, vector<int>& queries) {
	vll SA = constructSA(str);

	for (auto& query : queries)
		cout << SA[query] << " ";
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	ll N = 0;

	while (getline(cin >> ws, str)) {
		n = str.size();
		cin >> N;
		vector<int> queries(N);
		for (int i = 0; i < N; ++i)
			cin >> queries[i];
		suffixsorting(str, queries);
	}

	return 0;
}



