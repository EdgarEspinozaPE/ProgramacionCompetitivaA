// P_7 Planets and Kingdoms
// https://cses.fi/problemset/task/1683
#include <bits/stdc++.h>

using namespace std;

const int MAX = 9999999;
int N, M, resp[MAX];
bool visited[MAX];

vector<int> ord, comp, Tpa[MAX], Tpb[MAX];

void dfs1(int v) {
    visited[v] = true;
    for (int i : Tpa[v]) {
        if (!visited[i])
            dfs1(i);
    }

    ord.push_back(v);
}

void dfs2(int v) {

    visited[v] = true;
    comp.push_back(v);
    for (int i : Tpb[v]) {
        if (!visited[i])
            dfs2(i);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        Tpa[a].push_back(b);
        Tpb[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i])
            dfs1(i);
    }

    int K = 0;
    fill(visited + 1, visited + N + 1, false);
    reverse(ord.begin(), ord.end());

    for (int v : ord) {
        if (!visited[v]) {
            dfs2(v);
            K++;
            for (int i : comp)
                resp[i] = K;
            comp.clear();
        }
    }

    cout << K << "\n";
    for (int i = 1; i <= N; i++)
        cout << resp[i]<<" ";
    cout << "\n";
}