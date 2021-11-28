// P_10 Golnaldinho
// https://www.beecrowd.com.br/judge/en/problems/view/2792

#include <iostream>
#include <vector>

int MAX= 500005;

using namespace std;

int modPow2(int n)
{
	return n & (-n);
}

void update(vector<int>& tree, int node, int v)
{
	while (node < MAX)
	{
		tree[node] += v;
		node += modPow2(node);
	}
}

int query(vector<int>& tree, int node)
{
	int sum = 0;

	while (node > 0)
	{
		sum += tree[node];
		node -= modPow2(node);
	}
	return sum;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, nums, i;

	cin >> N;

	vector<int> tree(MAX, 0);

	for (i = 1; i <= N; i++)
	{
		cin >> nums;
		cout << (nums - query(tree, nums));

		if (i == N)
			cout <<"\n";
		else
			cout <<" ";

		update(tree, nums, 1);
	}

	return 0;
}