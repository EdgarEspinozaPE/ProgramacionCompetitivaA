//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
/* 
Ejemplo
5 8 10 2 15 7
output:
0 8 18 20 35 42
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,t;
	cin>>n;
	vector<int> v;
	vector<int> sum;
	sum.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> t;
		v.push_back(t);
		sum.push_back(t + sum.back());
	}
	for (int i : sum) {
		cout << i << " ";
	}
}
