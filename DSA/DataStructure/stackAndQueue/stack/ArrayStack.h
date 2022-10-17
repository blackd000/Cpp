#include "ArrayStack.c"

ArrayStack* createStack();
int getSize(ArrayStack* arrayStack);
int isEmptyStack(ArrayStack* arrayStack);
int isFullStack(ArrayStack* arrayStack);
void push(ArrayStack* arrayStack, char data);
char pop(ArrayStack* arrayStack);
void deleteStack(ArrayStack* arrayStack);
void printStack(ArrayStack* arrayStack);
