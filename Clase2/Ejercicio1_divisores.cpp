//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
/* 
Ejemplo
8 5 10 5 4 6 8 7 2 14 11
output: 2
*/

//Hallar la cantidad de divisores que hay en el arreglo de k
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
}
