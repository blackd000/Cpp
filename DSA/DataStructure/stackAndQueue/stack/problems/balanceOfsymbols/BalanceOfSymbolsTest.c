#include <stdio.h>
#include "BalanceOfSymbols.h"

int main() {
	const char* expression = "5 + [(9 * 3) - 18]";

	printf("Expression: %s\n", expression);
	printf("Is the symbols balance: %d\n", isCorrectExpression(expression));

	printf("\n");
	return 0;
}

