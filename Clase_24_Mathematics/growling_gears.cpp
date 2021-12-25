#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a = 0, b = 0, c = 0;
    double R;

    int n = 0, p = 0;
    cin >> p;
    while (p--) {
        cin >> n;
        pair<int, int> max = { 0,1 };
        for (int i = 0; i < n; i++) {
            cin >> a >> b >> c;
            double tp = -2.0 * a;
            R = -b / tp;
            double t = ((b * R) - (a * R * R) + (c));
            if (max.first < t) {
                max.first = t;
                max.second = i + 1;
            }
        }
        cout << max.second << "\n";
    }
    return 0;
}





