/*	Given a string Sof '('and ')', compute the minimum number of '('or ')'that needs to be added so that the resulting parentheses string is valid.Formally, a parentheses string is valid if and only if:
	●It is the empty string, or
	●It can be written as AB(Aconcatenated with B), where Aand Bare valid strings, or
	●It can be written as (A), where Ais a valid string. */

#include <iostream>
#include <string>
#include <stack>

int minAddToMakeValid(std::string s) {
    stack<std::string> oper;
    int cont = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            oper.push("(");
            cont++;
        }
        else if (s[i] == ')') {
            if (oper.empty() == true) {
                cont++;
            }
            else {
                oper.pop();
                cont--;
            }
        }

    }
    return cont;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s = "(((";
    std::cout << minAddToMakeValid(s) << "\n";
    return 0;
}