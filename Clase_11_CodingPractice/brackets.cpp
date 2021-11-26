#include <iostream>
#include <stack>

using namespace std;

int solution(string S) {
    stack<char> nested;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '(' || S[i] == '{' || S[i] == '[') {
            nested.push(S[i]);
        }
        else if (nested.empty()) {
            return 0;
        }
        else if (S[i] == ')' && nested.top() == '(') {
            nested.pop();
        }
        else if (S[i] == ']' && nested.top() == '[') {
            nested.pop();
        }
        else if (S[i] == '}' && nested.top() == '{') {
            nested.pop();
        }
        else return 0;
    }
    if (!nested.empty()) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "{[()()]}";
    cout << solution(s);

    return 0;
}