#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

unsigned int mod = 1000000007;

void optimal(int n,int time, vector<unsigned int> lis ) {
    unsigned int total_time=0, penalty = 0;
    for (unsigned int i = 0; i < lis.size(); i++) {
        unsigned int t = lis[i];
        if (total_time + t > time) {
            cout << i <<" "<< penalty;
            return;
        }
        total_time = total_time + t;
        
        penalty = penalty + total_time % mod;
    }
    cout << n <<" "<< penalty;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int n, t;
    cin >> n >> t;
    unsigned int a, b, c, t0;
    cin >> a >> b >> c >> t0;
    vector<unsigned int> lis(t0);
    lis[0] = t0;
    for (unsigned int i = 1; i < n; i++) {
        lis[i] = ((a * lis[i-1] + b) % c) + 1;
    }
    sort(lis.begin(), lis.end());
    optimal(n,t, lis);

    return 0;
}





