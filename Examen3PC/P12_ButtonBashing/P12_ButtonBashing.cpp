/*
Link P12: https://open.kattis.com/problems/buttonbashing
*/

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

pair<int, int> buttonbashing(vector<int>& buttons, int time) {

	unordered_map<int, bool> visitado;
	
	visitado[0] = true;
	visitado[time] = false;

	queue<int> busqueda;
	busqueda.push(0);

	int mov = 0;
	int minmov = 1e5 + 5;
	int minextra = 1e5 + 5;
	int nextnodes = 0;
	int currentnodes = 1;
	while (busqueda.empty()==false) {

		int curr = busqueda.front(); busqueda.pop();

		if (curr > time && curr < minextra) {
			minextra = curr - time;
			minmov = mov;
		}

		else if (curr == time)
			return { mov, 0 };

		for (auto& i : buttons) {
			int vecino;
			if (curr + i > 3600)
				vecino = 3600;
			else if (curr + i < 0)
				vecino = 0;
			else
				vecino = curr + i;

			if (!visitado[vecino]) {
				visitado[vecino] = true;
				busqueda.push(vecino);
				nextnodes++;
			}
		}

		currentnodes--;
		if (!currentnodes) {
			currentnodes = nextnodes;
			nextnodes = 0;
			mov++;
		}
	}

	return { minmov, minextra };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc,n, t;
	cin >> tc;
	while (tc--) {
		cin >> n >> t;
		vector<int> buttons(n);
		for (int i = 0; i < n; i++)
			cin >> buttons[i];
		pair<int,int> ans = buttonbashing(buttons, t);
		cout << ans.first << " " << ans.second << "\n";
	}

	return 0;
}