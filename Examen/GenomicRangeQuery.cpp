#include <iostream>
#include <vector>
using namespace std;

vector<int> genomicrange(string S, vector<int> P, vector<int> Q) {
    vector<int> R;
    int contadores[4] = {0,0,0,0};
    vector<int> A(S.size(), 0);
    vector<int> C(S.size(), 0);
    vector<int> G(S.size(), 0);
    vector<int> T(S.size(), 0);

    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'A')
            contadores[0]++;
        else if (S[i] == 'C')
            contadores[1]++;
        else if (S[i] == 'G')
            contadores[2]++;
        else if (S[i] == 'T')
            contadores[3]++;
        A[i] = contadores[0];
        C[i] = contadores[1];
        G[i] = contadores[2];
        T[i] = contadores[3];
    }
    for (int i = 0; i < P.size(); i++) {
        if (P[i] == Q[i]) {
            if (S[P[i]] == 'A')
                R.push_back(1);
            else if (S[P[i]] == 'C')
                R.push_back(2);
            else if (S[P[i]] == 'G')
                R.push_back(3);
            else if (S[P[i]] == 'T')
                R.push_back(4);
        }
        else if (A[P[i]] < A[Q[i]] || S[P[i]] == 'A')
            R.push_back(1);
        else if (C[P[i]] < C[Q[i]] || S[P[i]] == 'C')
            R.push_back(2);
        else if (G[P[i]] < G[Q[i]] || S[P[i]] == 'G')
            R.push_back(3);
        else if (T[P[i]] < T[Q[i]] || S[P[i]] == 'T')
            R.push_back(4);
    }
    return R;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string S = "CAGCCTA";
    vector<int> P;
    P.push_back(2);
    P.push_back(5);
    P.push_back(0);
    vector<int> Q;
    Q.push_back(4);
    Q.push_back(5);
    Q.push_back(6);
    vector<int> R = genomicrange(S, P, Q);
    for (auto i : R) {
        cout << i << " ";
    }
    return 0;
}
