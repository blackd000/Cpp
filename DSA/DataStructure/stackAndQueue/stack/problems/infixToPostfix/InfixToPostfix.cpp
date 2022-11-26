#include <iostream>
#include <string>
#include <stack>

using std::cout;
using std::endl;
using std::string;
using std::stack;

void infixToPostfix(string expression);
int getPriority(int priority[], const string operatorToCal, char eachCharacter);

int main() {
	string expression = "A*B-(C+D)+E"; // AB*CD+-E+
	/* string expression = "A+B*(C+D)+E"; // ABCD+*+E+ */
	/* string expression = "A*B-C+D+E";  // AB*C-D+E+ */
	/* const char *expression = "(A+B)*C-D"; // AB+C*D- */

	infixToPostfix(expression);

	cout << endl;
	return 0;
}

void infixToPostfix(string expression) {
	const string operatorToCal = "+-*/()";
	int priority[] = { 12, 12, 13, 13, 17, 17 };

	stack<char> S;

	for (int i = 0; i < expression.length(); i++) {
		if (operatorToCal.find_first_of(expression[i]) == -1) { // operands
			cout << expression[i];
		} else if (expression[i] == ')') { // right parentheses
			while (!S.empty()) {
				char token = S.top();
				if (token != '(') {
					cout << token;
					S.pop();
				} else {
					S.pop();
					break;
				}
			}
		} else {
			while (!S.empty()) {
				char token = S.top();
				if (token != '(' && 
						getPriority(priority, operatorToCal, token) >= getPriority(priority, operatorToCal, expression[i])) {
					cout << token;
					S.pop();
				} else {
					break;
				}
			}

			S.push(expression[i]);
		}
	}

	while (!S.empty()) {
		cout << S.top();
		S.pop();
	}
}

int getPriority(int priority[], const string operatorToCal, char eachCharacter) {
	return priority[operatorToCal.find_first_of(eachCharacter)];
}
