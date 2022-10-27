#include <stdio.h>
#include <string.h>
#include "../linkedListStack/LinkedListStack.h"

// - Time Complexity: O(n). Since we are scanning the input only once. 
// - Space Complexity: O(n) [forstack].
int isCorrectExpression(const char *expression);
int checkChar(const char *array, char character);

int main() {
	const char* expression = "5 + [(9 * 3) - 18]";

	printf("Expression: %s\n", expression);
	printf("Is the symbols balance: %d\n", isCorrectExpression(expression));

	printf("\n");
	return 0;
}

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
	for (int i = 0; i < strlen(array); i++) {
		if (array[i] == character) {
			return i;
		}
	}

	return -1;
}
