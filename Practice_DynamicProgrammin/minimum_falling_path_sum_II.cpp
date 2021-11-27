#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int mfps(vvi& grid, int i, int j, vvi& memo) {
	if (memo[i][j] != INT_MAX)
		return memo[i][j];

	int result;
	if (i == 0)
		result = grid[i][j];
	else {
		int minimum = INT_MAX;
		for (int k = 0; k < grid.size(); ++k) {
			if (k == j)
				continue;
			int local_sum = grid[i][j] + mfps(grid, i - 1, k, memo);
			minimum = min(minimum, local_sum);
		}
		result = minimum;
	}
	memo[i][j] = result;
	return result;
}

int minFallingPathSum(vvi& grid) {
	int n = grid.size();

	vvi memo(n, vi(n, INT_MAX));
	int minimum = INT_MAX;
	for (int i = 0; i < n; ++i)
		minimum = min(minimum, mfps(grid, n - 1, i, memo));

	return minimum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vvi grid;

	grid = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	cout << minFallingPathSum(grid) << "\n";

	grid = { { 7 } };
	cout << minFallingPathSum(grid) << "\n";

	return 0;
}