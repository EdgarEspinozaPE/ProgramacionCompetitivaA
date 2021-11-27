#include <iostream>
#include <vector>

using namespace std;

int tiling_memoized(int n, vector<int>& memo) {
	if (memo[n])
		return memo[n];

	int result;
	if (n <= 1)
		result = n;
	else
		result = tiling_memoized(n - 1, memo) + tiling_memoized(n - 2, memo);

	memo[n] = result;
	return result;
}

int tiling(int n) {
	vector<int> memo(n + 1, 0);
	return tiling_memoized(n, memo);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	n = 8;
	cout << tiling(n) << "\n";

	n = 12;
	cout << tiling(n) << "\n";

	return 0;
}