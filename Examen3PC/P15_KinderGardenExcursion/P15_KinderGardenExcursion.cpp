/*
Link P15: https://open.kattis.com/problems/excursion
*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll cont, val;
    string str;
    vll cdigits (3,0);
    cin >> str;
    cont = 0;
    for (int i = 0; i < str.size(); i++) {
        val = str[i] - '0';
        for (int j = val + 1; j < 3; j++) {
            cont += cdigits[j];
        }
        cdigits[val]++;
    }
    cout << cont << "\n";
    return 0;
}