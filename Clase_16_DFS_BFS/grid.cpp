#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minimum_moves(vector<vector<int>>& grid) {
	vector<vector<bool>> visited(grid.size());
	for (int i = 0; i < grid.size(); ++i)
		visited[i].resize(grid[0].size(), false);

	pair<int, int> goal = { grid.size() - 1, grid[0].size() - 1 };
	visited[0][0] = true;

	queue<pair<int, int>> search;
	search.push({ 0, 0 });

	vector<int> dr = { -1, 0, 1, 0 };
	vector<int> dc = { 0, 1, 0, -1 };

	int moves = 0;
	int nodes_in_current_depth = 1;
	int nodes_in_next_depth = 0;

	while (!search.empty() && search.front() != goal) {
		auto curr = search.front(); search.pop();
		int r = curr.first;
		int c = curr.second;
		int jump_size = grid[r][c];
		for (int i = 0; i < 4; ++i) {
			if ((0 <= r + dr[i] * jump_size) && (r + dr[i] * jump_size < grid.size()) &&
				(0 <= c + dc[i] * jump_size) && (c + dc[i] * jump_size < grid[0].size()) &&
				(!visited[r + dr[i] * jump_size][c + dc[i] * jump_size])) {
				visited[r + dr[i] * jump_size][c + dc[i] * jump_size] = true;
				search.push({ r + dr[i] * jump_size, c + dc[i] * jump_size });
				++nodes_in_next_depth;
			}
		}
		--nodes_in_current_depth;
		if (!nodes_in_current_depth) {
			nodes_in_current_depth = nodes_in_next_depth;
			nodes_in_next_depth = 0;
			++moves;
		}
	}

	if (visited[goal.first][goal.second])
		return moves;
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<int>> grid;
	int n, m;
	cin >> n >> m;
}