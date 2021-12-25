#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

const int limit = 1000001;

int p = 2;
int nums[limit];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;

    nums[0] = 0;

    double digits = 0;

    for (int i = 1; i < limit; i++) {
        digits += log10(i);
        nums[i] = digits;
    }

    while (cin >> n) {
        if (n == -20)
            break;
        cout << nums[n] + 1 << "\n";
    }
    return 0;
}




