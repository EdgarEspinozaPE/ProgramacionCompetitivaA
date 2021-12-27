/*
Link P3: https://open.kattis.com/problems/collatz
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll next_collatz(ll& n) {
	n = (n & 1) ? 3 * n + 1 : n / 2;
	return n;
}

vll generate_sequence(ll a) {
	vll seq;
	seq.push_back(a);
	while (a > 1) {
		seq.push_back(next_collatz(a));
	}
	return seq;
}

ll search(vll v, ll n) {
	for (ll i = 0; i < v.size(); i++) {
		if (v[i] == n)
			return i;
	}
	return -1;
}

void collatzconjecture(ll& A, ll& B) {
	vll seqA, seqB;
	seqA = generate_sequence(A);
	seqB = generate_sequence(B);

	ll stepsA, stepsB;
	for (stepsA = 0; stepsA < seqA.size(); stepsA++) {
		stepsB = search(seqB, seqA[stepsA]);
		if (stepsB != -	1)
			break;
	}
	cout << A << " needs " << stepsA << " steps, " << B << " needs " << stepsB << " steps, ";
	cout << "they meet at " << seqA[stepsA] << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll A, B;
	while (cin >> A >> B && A && B)
		collatzconjecture(A, B);
	return 0;
}



