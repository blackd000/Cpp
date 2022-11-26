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
 *   FUNCTION void infixToPostfix(string expression)
 * 		CREATE a stack
 * 		LOOP through the input stream
 * 			IF encounter an Operand 
 * 				OUTPUT eachCharacter
 * 			ELSE IF encounter a right parentheses 
 * 				WHILE a left parentheses is not POPPED (but not OUTPUT)
 * 					POP and OUTPUT tokens
 * 				END WHILE
 * 			ELSE IF encounter an operator or left parentheses 
 * 				POP and OUTPUT tokens 
 * 				WHILE a left parentheses is not encountered and token's priority is greater
 * 				than or equal to eachCharacter's token
 * 					POP and OUTPUT tokens
 * 				END WHILE
 * 				PUSH eachCharacter into stack
 * 			END IF
 * 		END LOOP
 * 		WHILE the stack is not empty
 * 			POP and OUTPUT tokens 
 * 		END WHILE
 *
 * VD: A*B-(C+D)+E = AB*CD+-E+
 */


void infixToPostfix(const char *expression);

int checkChar(const char *operatorToCal, char eachCharacter);

int getPriority(int priority[], const char *operatorToCal, char eachCharacter);

#endif
