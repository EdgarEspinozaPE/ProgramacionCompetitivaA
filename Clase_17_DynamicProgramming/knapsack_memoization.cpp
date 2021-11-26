#include <iostream>
#include <vector>

using namespace std;

int knapsack_aux(int n, int C, vector<int> w, vector<int> v, vector<vector<int>>& memo) {
	if (memo[n][C] != -1)
		return memo[n][C];

	int result;
	if (!n || !C)
		result = 0;
	else if (w[n] > C)
		result = knapsack_aux(n - 1, C, w, v, memo);
	else {
		int tmp1 = knapsack_aux(n - 1, C, w, v, memo);
		int tmp2 = v[n] + knapsack_aux(n - 1, C - w[n], w, v, memo);
		result = max(tmp1, tmp2);
	}

	memo[n][C] = result;
	return result;
}

int knapsack(int n, int C, vector<int> w, vector<int> v) {
	vector<vector<int>> memo(n + 1, vector<int>(C + 1, -1));
	return knapsack_aux(n, C, w, v, memo);
}

int main(int argc, char const* argv[]) {

	int n, C;
	vector<int> w, v;
	
	n = 5;
	C = 10;
	w = { 0, 1, 2, 4, 2, 5 };
	v = { 0, 5, 3, 5, 3, 2 };
	cout << knapsack(n, C, w, v) << "\n";

	return 0;
}