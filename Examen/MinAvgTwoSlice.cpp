#include <iostream>
#include <vector>
using namespace std;

int minaverage(vector<int> A) {
    float minimo = 1000000;
    int mindex = 0;
    for (int i = 0; i < A.size() - 2; i++) {
        float aux1 = (A[i] + A[i + 1] + A[i + 2])/3.0f;
        float aux2 = (A[i] + A[i + 1])/2.0f;
        if (minimo > aux1 || minimo > aux2) {
            minimo = min(aux1,aux2);
            mindex = i;
        }
    }
    if (minimo > (A[A.size() - 1] + A[A.size() - 2])/2)
        return (A.size() - 2);
    return mindex;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> A;
    A.push_back(4);
    A.push_back(2);
    A.push_back(2);
    A.push_back(5);
    A.push_back(1);
    A.push_back(5);
    A.push_back(8);
    cout << minaverage(A);
}

