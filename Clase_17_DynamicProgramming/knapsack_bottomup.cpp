#include <iostream>
#include <vector>

using namespace std;

int knapsack_bottomup(int n, int C, vector<int> w, vector<int> v) {
	vector<vector<int>> KS(n + 1, vector<int>(C + 1, 0));

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= C; ++j)
			if (w[i] > j)
				KS[i][j] = KS[i - 1][j];
			else
				KS[i][j] = max(KS[i - 1][j], v[i] + KS[i - 1][j - w[i]]);

	return KS[n][C];
}

int main(int argc, char const* argv[]) {

	int n, C;
	vector<int> w, v;
	
	n = 5;
	C = 10;
	w = { 0, 1, 2, 4, 2, 5 };
	v = { 0, 5, 3, 5, 3, 2 };
	cout << knapsack_bottomup(n, C, w, v) << "\n";

	return 0;
}