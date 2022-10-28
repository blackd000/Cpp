#ifndef INFIXTOPOSTFIX_H
#define INFIXTOPOSTFIX_H

#include <stdio.h>
#include <string.h>
#include "../../linkedListStack/LinkedListStack.h"

/* 
 * - Definitions:
 *   	+ Infix: An infix expression is a single letter, or an operator, 
 * proceeded by one infix string andfollowed by another Infix string
 * 		+ Prefix: A prefix expression is a single letter, or an operator, 
 * followed by two prefix strings. Every prefix string longer than 
 * a single variable contains an operator, first operand and second 
 * operand.
 * 		+ Postfix: A postfix expression (also called Reverse Polish Notation) 
 * is a single letter or an operator, preceded by two postfix strings. 
 * Every postfix string longer than a single variable contains first 
 * and second operands followed by an operator.
 *
 * - Important Properties:
 * 		+ Let us consider the infix expression 2 + 3 * 4 and its postfix equivalent 234*+. Notice
 * that between infix and postfix the order of the numbers (or operands) is unchanged.
 * It is 2 3 4 in both cases. But the order of the operators * and + is affected in the two
 * expressions.
 * 		+ Only one stack is enough to convert an infix expression to postfix expression. The
 * stack that we use in the algorithm will be used to change the order of operators from
 * infix to postfix. The stack we use will only contain operators and the open parentheses 
 * symbol ‘(‘.
 * 		+ Postfix expressions do not contain parentheses. We shall not output the parentheses in the postfix
 * output.
 *
 * - Algorithm:
 * 		a) Create a stack
 * 		b) For each character eachCharacter in the input stream {
 * 			1) If eachCharacter is an Operand Then output eachCharacter
	* 		2) If eachCharacter is a right parentheses Then pop and output tokens until
	* 		a left parentheses is popped (but not output)
	* 		3) If eachCharacter is an operator or left parentheses Then pop and output tokens
	* 		util one of lower priority than eachCharacter is encountered or a left parentheses
	* 		is encountered or the stack is empty and push eachCharacter
	* 	}
	* 	c) pop and output tokens until the stack is empty
	*
	* A*B-(C+D)+E = AB*CD+-E+
 */


void infixToPostfix(const char *expression);

int checkChar(const char *operator, char eachCharacter);

int getPriority(int priority[], const char *operator, char eachCharacter);

#endif
