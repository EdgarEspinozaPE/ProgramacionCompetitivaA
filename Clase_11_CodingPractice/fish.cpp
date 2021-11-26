#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int>& A, vector<int>& B) {
    int n = B.size(), surv = 0;
    stack<int> fish;
    for (int i = 0; i < n; i++) {
        if (B[i] == 1) {
            fish.push(A[i]);
        }
        else {
            while (fish.size() != 0) {
                if (fish.top() < A[i]) {
                    fish.pop();
                }
                else break;
            }
            if (fish.empty()) {
                surv++;
            }
        }
    }
    surv += fish.size();
    return surv;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> A = { 4,3,2,1,5 };
    vector<int> B = { 0,1,0,0,0 };

    cout << solution(A, B);

    return 0;
}