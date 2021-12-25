#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double x, xx, b, r;
    int p;

    while (cin >> x) {
        if (x == 0)
            break;
        xx = fabs(x);
        for (b = 2; (r = b * b) <= xx; b++) {

            for (p = 2; r < xx; p++)
                r *= b;
            if (r == xx)
                if (x > 0 || p % 2) {
                    cout << p << "\n";
                }
        }
    }
    return 0;
}




