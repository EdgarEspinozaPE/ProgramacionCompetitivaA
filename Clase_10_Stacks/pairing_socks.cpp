/*	The first line of input contains the integer n (1≤n≤105) as described above. 
	The next line contains 2n integers a1,…,a2n (1≤ai≤109 for each i), 
	where ai denotes the type of sock number i. Initially, 
	sock 1 is at the top of the pile and sock 2n is at the bottom. */

#include <iostream>
#include <stack>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::stack<int> sock;
	int n = 0, x = 0;
	std::cin >> n;
	for (int i = 0; i < n * 2; i++) {
		std::cin >> x;
		if (sock.empty() || sock.top() != x) {
			sock.push(x);
		}
		else {
			sock.pop();
		}
	}
	if (sock.empty()) {
		std::cout << n * 2 << "\n";
	}
	else {
		std::cout << "impossible";
	}

	return 0;
}