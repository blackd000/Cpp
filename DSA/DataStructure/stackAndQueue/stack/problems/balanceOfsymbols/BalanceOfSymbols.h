#ifndef BALANCEOFSYMBOLS_H
#define BALANCEOFSYMBOLS_H

#include <stdio.h>
#include <string.h>
#include "../../linkedListStack/LinkedListStack.h"

/*
 * - Algorithm:
 * 		a) Create a stack.
 * 		b) While (end of input is not reached) {
 * 			1) If the character read is not a symbol to be balanced, ignore it.
 * 			2) If the character is an opening symbol like (, [, {, push it onto the stack
 * 			3) Else If it is a closing symbol like ),],}, then if the stack is empty report an
 * 			error. Otherwise pop the stack.
 * 			4) If the symbol popped is not the corresponding opening symbol, report an
 * 			error.
 * 		}
 * 		c) At end of input, if the stack is not empty report an error
 *
 * - Time Complexity: O(n). Since we are scanning the input only once. 
 * - Space Complexity: O(n) [for stack].
 */
int isCorrectExpression(const char *expression);

int checkChar(const char *array, char character);

#endif
