/*	Reverse Polish Notation (RPN) Writing “2 3 +” instead of “2+3”.
    Valid operators are +, -, *, /.
    Each operand may be an integer or another expression. */

#include <iostream>
#include <stack>
#include <vector>
#include <string>

int evalRPN(std::vector<std::string>& tokens) {
	std::stack<int> evaluator;
	for (auto& i : tokens) {
		if (i == "+") {
			int b = evaluator.top(); evaluator.pop();
			int a = evaluator.top(); evaluator.pop();
			evaluator.push(a + b);
		}
		else if (i == "-") {
			int b = evaluator.top(); evaluator.pop();
			int a = evaluator.top(); evaluator.pop();
			evaluator.push(a - b);
		}
		else if (i == "*") {
			int b = evaluator.top(); evaluator.pop();
			int a = evaluator.top(); evaluator.pop();
			evaluator.push(a * b);
		}
		else if (i == "/") {
			int b = evaluator.top(); evaluator.pop();
			int a = evaluator.top(); evaluator.pop();
			evaluator.push(a / b);
		}
		else {
			evaluator.push(stoi(i));
		}
	}
	return evaluator.top();
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::string> tokens;

	tokens = { "4", "13", "5", "/", "+" };
	std::cout << evalRPN(tokens) << "\n";

	return 0;
}