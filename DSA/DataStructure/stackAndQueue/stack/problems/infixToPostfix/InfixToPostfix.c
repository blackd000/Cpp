#include "InfixToPostfix.h"

void infixToPostfix(const char *expression) {
	const char *operator = "+-*/()";
	int priority[] = { 12, 12, 13, 13, 17, 17 };

	Stack **stack = (Stack **) malloc(sizeof(Stack *));

	int n = strlen(expression);
	for (int i = 0; i < n; i++) {
		if ((checkChar(operator, expression[i]) == -1) && expression[i] != '(' && expression[i] != ')') { // operand
			printf("%c", expression[i]);
		} else if (expression[i] == ')') { // right parentheses
			char token;
			while (!isEmptyStack(*stack) && (token = pop(stack)) != '(') {
				printf("%c", token);
			}
		} else { // operator or left parentheses
			char token;
			while (!isEmptyStack(*stack)) {
				token = top(*stack);
				if (token == '(' ||
						getPriority(priority, operator, token) < getPriority(priority, operator, expression[i])) {
					break;
				} else {
					printf("%c", token);
					pop(stack);
				}
			}
			push(stack, expression[i]);
		}
	}

	while (!isEmptyStack(*stack)) {
		printf("%c", pop(stack));
	}
}

int checkChar(const char *operator, char eachCharacter) {
	int n = strlen(operator);
	for (int i = 0; i < n; i++) {
		if (eachCharacter == operator[i]) {
			return i;
		}
	}

	return -1;
}

int getPriority(int priority[], const char *operator, char eachCharacter) {
	return priority[checkChar(operator, eachCharacter)];
}
