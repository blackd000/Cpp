#include "BalanceOfSymbols.h"

int isCorrectExpression(const char* expression) {
	const char* open = "([{";
	const char* close = ")]}";
	Stack **stack = (Stack **) malloc(sizeof(Stack *));

	int n = strlen(expression);
	for (int i = 0; i < n; i++) {
		if (checkChar(open, expression[i]) != -1) {
			push(stack, expression[i]);
		} else if (checkChar(close, expression[i]) != -1) {
			if (isEmptyStack(*stack)) {
				return 0;
			}

			char openCharacterInStack = pop(stack);
			if (checkChar(close, expression[i]) != checkChar(open, openCharacterInStack)) {
				return 0;
			}
		}
	}

	return (isEmptyStack(*stack));
}

int checkChar(const char* array, char character) {
	int n = strlen(array);
	for (int i = 0; i < n; i++) {
		if (array[i] == character) {
			return i;
		}
	}

	return -1;
}
