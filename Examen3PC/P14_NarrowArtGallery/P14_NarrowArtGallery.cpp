/*
Link P14: https://open.kattis.com/problems/narrowartgallery
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int nagdp(vvi& gallery, int k, int row, int col, vvvi& Gallery) {
	
	if (!k)
		return 0;

	
	else if (row < 0)
		return 1e9;
	
	else if (Gallery[k][row][col] != -1)
		return Gallery[k][row][col];
	
	int temp = min(nagdp(gallery, k, row - 1, col ^ 1, Gallery), nagdp(gallery, k, row - 1, col, Gallery));
	int ans = min(nagdp(gallery, k - 1, row - 1, col, Gallery) + gallery[row][col], temp);

	Gallery[k][row][col] = ans;
	return ans;
}

int narrowartgallerie(vvi& gallery, int k) {
	int n = gallery.size();
	vvvi Gallery(k + 1, vvi(n, vi(2, -1)));
	return min(nagdp(gallery, k, n - 1, 1, Gallery), nagdp(gallery, k, n - 1, 0, Gallery));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, k, v;
	cin >> N >> k;

	int totalv = 0;
	vvi gallery(N, vi(2));
	for (int i = 0; i < N; ++i) {
		cin >> gallery[i][0] >> gallery[i][1];
		totalv += (gallery[i][0] + gallery[i][1]);
	}

	int stop1, stop2;
	cin >> stop1 >> stop2;	

	cout << totalv - narrowartgallerie(gallery, k) << "\n";

	return 0;
}