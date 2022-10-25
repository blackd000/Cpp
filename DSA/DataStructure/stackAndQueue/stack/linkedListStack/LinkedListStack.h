#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../../../linkedList/singlyLinkedList/SinglyLinkedList.h"
/* #include "/home/keilar/Programming/Cpp/DSA/DataStructure/linkedList/singlyLinkedList/SinglyLinkedList.h" */

typedef Node Stack;

void push(Stack **top, int data);

int pop(Stack **top);

int top(Stack *top);

int isEmptyStack(Stack *top);

void deleteStack(Stack **top);

void printStack(Stack **top);


#endif
