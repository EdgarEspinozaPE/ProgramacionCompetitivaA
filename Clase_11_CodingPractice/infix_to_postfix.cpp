#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

map<char, int> ord;

void init() {
    ord['+'] = 1;
    ord['-'] = 1;
    ord['*'] = 2;
    ord['/'] = 2;
    ord['^'] = 3;
}

void solve(string& str) {
    stack<char> s;
    string res = "";

    
    

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') {
            while (!s.empty() && ord[s.top()] >= ord[str[i]]) {
                res += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
        else if (str[i] == '(') s.push(str[i]);
        else if (str[i] == ')') {
            while (s.top() != '(') {
                res += s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            res += str[i];
        }
    }
    while (!s.empty()) {
        res += s.top();
        s.pop();
    }

    cout << res << endl;
}

int main(int argc, char const* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string str;
    init();
    cin >> N;
    while (N--)
    {
        cin >> str;
        solve(str);
    }

    return 0;
}