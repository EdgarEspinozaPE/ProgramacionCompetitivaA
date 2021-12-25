#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

double N, L, W, x, r;

void distance(vector<pair<double, double>> lis, double L) {


    double c = 0, i = 0, aux = 0;
    double n = lis.size();

    while (true) {
        double tmp = -1;
        while (i < n && lis[i].first <= aux) {
            tmp = max(tmp, lis[i].second);
            i++;
        }
        if (tmp == -1) {
            cout << -1 << "\n";
            return;
        }
        c++;
        aux = tmp;
        if (aux >= L) {
            cout << c << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> N >> L >> W) {
        vector<pair<double, double>> lis;
        for (int i = 0; i < N;i++) {
            cin >> x >> r;
            if (2 * r > W) {
                double d = sqrt(pow(r, 2) - pow(W / 2, 2));
                lis.push_back(pair<double, double>(x - d, x + d));
            }
        }
        sort(lis.begin(), lis.end());
        distance(lis, L);
    }

    return 0;
}





