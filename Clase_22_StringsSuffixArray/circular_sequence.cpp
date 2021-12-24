#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	string sequence, first, second;
	cin >> T;
	while (T--) {
		cin >> sequence;

		int size = sequence.length();
		vector<string> store;
		store.push_back(sequence);

		for (int i = 1; i < size; i++) {
			first = sequence.substr(i);
			second = sequence.substr(0, i);
			store.push_back(first + second);
		}
		sort(store.begin(), store.end());

		cout << store[0] << "\n";
	}
	return 0;
}
