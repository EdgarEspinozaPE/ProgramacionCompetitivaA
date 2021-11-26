#include <iostream>
#include <utility>
#include <iomanip>
#include <vector>
#include <deque>

using namespace std;

vector<pair<int, int>> dole(int N, int k, int m) {
	vector<pair<int, int>> chosen;

	deque<int> deq(N);
	for (int i = 0; i < N; ++i)
		deq[i] = i + 1;

	int i = 0;
	int j = N - 1;

	int total = 0;
	while (total < N) {
		for (int p = 0; p < k - 1 || !deq[i]; ++p) {
			if (!deq[i])
				--p;
			i = (++i) % N;
		}

		for (int q = 0; q < m - 1 || !deq[j]; ++q) {
			if (!deq[j])
				--q;
			j = (j + N - 1) % N;
		}

		chosen.push_back({ deq[i], deq[j] });

		++total;
		if (i != j)
			++total;
		deq[i++] = 0; i %= N;
		deq[j--] = 0; j = (j + N) % N;
	}

	return chosen;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<pair<int, int>>> doles;

	int N, k, m;
	while (true) {
		cin >> N >> k >> m;
		if (!N && !k && !m)
			break;

		doles.push_back(dole(N, k, m));
	}

	for (auto& dole : doles) {
		for (int i = 0; i < (int)dole.size(); ++i) {
			if (i)
				cout << ",";
			cout << setw(3);
			cout << dole[i].first;
			if (dole[i].first != dole[i].second) {
				cout << setw(3);
				cout << dole[i].second;
			}
		}
		cout << "\n";
	}

	return 0;
}