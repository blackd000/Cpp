#include <stdio.h>
#include <string.h>
#include "../linkedListStack/LinkedListStack.h"

int isCorrectExpression(const char *expression);
int checkChar(const char *array, char character);

int main() {
	const char* expression = "5 + [(9 * 3) - 18]";

	printf("%d", isCorrectExpression(expression));

	printf("\n");
	return 0;
}

int isCorrectExpression(const char* expression) {
	const char* open = "([{";
	const char* close = ")]}";
	Stack **arrayStack = (Stack **) malloc(sizeof(Stack *));

	int n = strlen(expression);
	for (int i = 0; i < n; i++) {
		if (checkChar(open, expression[i]) != -1) {
			push(arrayStack, expression[i]);
		} else if (checkChar(close, expression[i]) != -1) {
			if (isEmptyStack(*arrayStack)) {
				return 0;
			}
			if (checkChar(close, expression[i]) != checkChar(open, pop(arrayStack))) {
				return 0;
			}
		}
	}

	return (isEmptyStack(*arrayStack));
}

int checkChar(const char* array, char character) {
	for (int i = 0; i < strlen(array); i++) {
		if (array[i] == character) {
			return i;
		}
	}

	return -1;
}
