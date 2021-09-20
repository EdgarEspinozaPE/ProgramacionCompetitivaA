// PC clase1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

/* //Ejercicio#1
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k,t,c=0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t % k == 0)
			c++;
	}
	cout << c << "\n";
}*/

/* //Ejercicio#2
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
}*/

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