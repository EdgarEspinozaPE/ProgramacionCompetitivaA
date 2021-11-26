#include <iostream>
#include <vector>

using namespace std;

int knapsack(int n, int C, vector<int> w, vector<int> v) {
	if (!n || !C)
		return 0;

	if (w[n] > C)
		return knapsack(n - 1, C, w, v);

	int tmp1 = knapsack(n - 1, C, w, v);
	int tmp2 = v[n] + knapsack(n - 1, C - w[n], w, v);
	return max(tmp1, tmp2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, C;
	vector<int> w, v;

	n = 5;
	C = 10;
	w = { 0, 1, 2, 4, 2, 5 };
	v = { 0, 5, 3, 5, 3, 2 };
	cout << knapsack(n, C, w, v) << "\n";

	return 0;
}