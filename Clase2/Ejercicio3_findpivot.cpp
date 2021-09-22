//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

/*
Ejemplo
6 1 7 3 6 5 6
output: 3

4 1 2 3 4
output: -1
*/

//Funcion para encontrar la posicion del pivot en un arreglo
int findpivot(vector<int> nums, vector<int> sum,int n) {
	for (int i = 1; i < n; i++) {
		if (sum[i] * 2 == sum.back() - nums[i]) {
			return i;
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v;
	vector<int> sum;
	sum.push_back(0);
	int n, end=0;
	cin >> n;
	for(int i = 0;i<n;i++) {
		std::cin >> end;
		v.push_back(end);
		sum.push_back(end + sum.back());
	}
	cout << findpivot(v, sum, n);
}
