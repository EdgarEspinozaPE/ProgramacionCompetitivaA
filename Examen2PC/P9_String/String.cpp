//P_9 Strings
//https://www.beecrowd.com.br/judge/en/problems/view/2917

#include <bits/stdc++.h>
using namespace std;

void strin(vector<long long>& str, long long s) {
    long long maxlocal = 0, maxglobal = INT_MIN;
    long long i = 0, j = 0, px = 0;
    bool restarted = false;
    while (i < s) {
        if (j == (str.size())) {
            j = 0;
            restarted = true;
        }

        maxlocal = maxlocal + str[j];

        if (px == j && restarted == true)
            break;
        else
            if (maxglobal < maxlocal)
                maxglobal = maxlocal;

        if (maxlocal <= 0) {
            if (j == (str.size()) - 1)
                px = 0;
            else
                px = j + 1;

            maxlocal = 0;
        }
        i++;
        j++;
    }
    cout << maxglobal << "\n";
}

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    while (cin >> M) {
        vector<long long> str(M * 10, 0);
        for (int i = 0; i < M * 10; i++) {
            cin >> str[i];
        }

        long long s = M * 20;

        strin(str, s);

    }

    return 0;
}