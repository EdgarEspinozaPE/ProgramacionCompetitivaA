#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int a[10];
    bool table[1000001];


    while (cin >> n >> m) {
        for (int i = 0; i < m; i++) cin >> a[i];

        table[0] = false;
        for (int i = 1; i <= n; i++) {
            table[i] = false;

            for (int j = 0; j < m; j++)
                if (i >= a[j] && !table[i - a[j]]) {
                    table[i] = true;
                    break;
                }
        }

        if (table[n])
            cout << "Stan wins\n";
        else
            cout << "Ollie wins\n";
    }

    return 0;
}


