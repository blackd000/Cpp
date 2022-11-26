#include <iostream>
#include <string>
#include <stack>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::stack;

// - Algorithms:
// 	FUNCTION void dinhGiaBieuThuc(string postfixExpression)
// 		CREATE a empty stack
// 		LOOP through the input stream
// 			IF encounter an Operand
// 				PUSH into the stack
// 			ELSE IF encounter an Operator
// 				POP 2 values from the stack
// 				CALCULATE (+-*/) them 
// 				PUSH the calculate value into the stack
// 			END IF
// 		END LOOP
// 		OUTPUT the only value in the stack


void dinhGiaBieuThuc(string postfixExpression);
void checkChar(const string operatorToCal, char eachCharacter);

int main() {
	/* string expression = "18 25 * 15 /"; */
	string expression = "10 5 + 2 * 3 /";

	dinhGiaBieuThuc(expression);

	cout << endl;
	return 0;
}

void dinhGiaBieuThuc(string expression) {
	const string operatorToCal = "+-*/";

	stack<string> S;

	int start = 0;
	int end = -1;

	string eachLetter;

	do {
		start = end + 1; // 1 is the delimeter's size
		end = expression.find_first_of(' ', start);

		eachLetter = expression.substr(start, end - start);

		/* cout << eachLetter << " "; */

		if (operatorToCal.find(eachLetter) == -1) { // operands 
			S.push(eachLetter);
		} else { // operators
			int total;

			// because it push into a stack so come out first is number2
			int number2 = stoi(S.top());
			S.pop();
			int number1 = stoi(S.top());
			S.pop();

			if (eachLetter.compare("+") == 0) { // if eachLetter is "+"
				total = number1 + number2;
				cout << number1 << " + " << number2 << " = " << total << " is +" << endl;
			} else if (eachLetter.compare("-") == 0) {
				total = number1 - number2;
				cout << number1 << " - " << number2 << " = " << total << " is -" << endl;
			} else if (eachLetter.compare("*") == 0) {
				total = number1 * number2;
				cout << number1 << " * " << number2 << " = " << total << " is *" << endl;
			} else if (eachLetter.compare("/") == 0) {
				total = number1 / number2;
				cout << number1 << " / " << number2 << " = " << total << " is /" << endl;
			}

			S.push(to_string(total));
		}

	} while (end != -1);

	cout << "Final: " << S.top() << endl;
}
