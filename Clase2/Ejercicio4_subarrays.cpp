//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

/*
Ejemplo
6 4 5 0 -2 -3 1 5
Output: 7
*/

//Funcion para encontrar subarrays cuya suma es divisible por k
int findsubarrays(vector<int> nums, int n, int k) {
	int c = 0;
	int j = 0;
	vector<int> sum;
	for (int i = 0; i < n; i++) {
		sum.push_back(0);
		for (int x = j; x < n; x++) {
			sum.push_back(nums[x] + sum.back());
		}
		if (nums[i] % k == 0)
			c++;
		if (sum[i + 1] % k == 0) {
			c++;
		}
		j++;
		sum.clear();
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v;
	int n, end = 0, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> end;
		v.push_back(end);
	}
	cin >> k;
	cout << findsubarrays(v, n, k);
}
