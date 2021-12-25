#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n, first, r, p;
    while (cin >> n) {

        if (n == 0) 
            break;

        --n;
        cout << "{";

        p = 0;
        first = 1;
        while (n > 0) {
            r = n % 2;
            if (r == 1) {
                if (first == 0)
                    cout << ", ";
                else
                    cout << " ";
                first = 0;
                cout << fixed << setprecision(0);
                cout << pow(3, p);
            }
            n = n / 2;
            p++;
        }
        cout << " }" << "\n";
    }

    return 0;
}



