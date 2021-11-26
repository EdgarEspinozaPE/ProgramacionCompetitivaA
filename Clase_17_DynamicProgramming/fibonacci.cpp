#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long fibonacci(long n) {
	if (n <= 1)
		return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	n = 8;
	cout << fibonacci(n) << "\n";

	n = 12;
	cout << fibonacci(n) << "\n";

	return 0;
}