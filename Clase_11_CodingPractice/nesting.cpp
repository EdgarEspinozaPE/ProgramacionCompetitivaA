#include <iostream>
#include <queue>

using namespace std;

int solution(string& S) {
    queue<char> nest;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '(') {
            nest.push(S[i]);
        }
        else if (nest.empty()) {
            return 0;
        }
        else if (nest.front() == '(') {
            nest.pop();
        }
    }
    if (!nest.empty()) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "(()())";
    cout << solution(s);

    return 0;
}