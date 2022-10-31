#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../../../linkedList/singlyLinkedList/SinglyLinkedList.h"
/* #include "/home/keilar/Programming/Cpp/DSA/DataStructure/linkedList/singlyLinkedList/SinglyLinkedList.h" */

typedef Node Stack;

// - Time Complexity: O(1) (Average)
void push(Stack **top, int data);

// - Time Complexity: O(1)
int pop(Stack **top);

// - Time Complexity: O(1)
int top(Stack *top);

// - Time Complexity: O(1)
int isEmptyStack(Stack *top);

// - Time Complexity: O(n)
void deleteStack(Stack **top);

// - Time Complexity: O(n)
void printStack(Stack *top);

#endif
