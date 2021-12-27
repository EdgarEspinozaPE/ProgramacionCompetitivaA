/*
Link P11: https://open.kattis.com/problems/fire2
*/

#include <iostream>
#include <vector>

using namespace std;

vector <vector<char>> building(1001, vector<char>(1001));
pair<int, int> inicio,pos,bfs[1000000];
int x[4] = { 0,0,1,-1 }, y[4] = { 1,-1,0,0 };

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc, caseiter, w, h, i, j, i2, j2, l, time, sc;

    bool possible;

    cin >> tc;
    for (caseiter = 1; caseiter <= tc; caseiter++) {
        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> building[i][j];
            }            
        }
        l = 0;
        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                if (building[i][j] == '@') {
                inicio = make_pair(i, j);
                }
                else if (building[i][j] == '*') {
                    bfs[l++] = make_pair(i, j);
                }             
            }
        }

        time = 0;
        bfs[l++] = inicio;
        sc = l;
        possible = false;
        for (int crr = 0; !possible && crr < l; crr++) {
            if (crr == sc) {
                sc = l;
                time++;
            }
            pos = bfs[crr];
            j = pos.second;
            i = pos.first;
            for (int d = 0; d < 4; d++) {
                i2 = i + x[d];
                j2 = j + y[d];
                if (i2 >= h || i2 < 0 || j2 < 0 || j2 >= w) {
                    if (building[i][j] == '@')
                        possible = true;
                }
                else if (building[i2][j2] == '.') {
                    building[i2][j2] = building[i][j];
                    bfs[l++] = make_pair(i2, j2);
                }
            }
        }
        if (possible) {
            cout << time + 1 << "\n";
        }
        else {
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}