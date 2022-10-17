#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* prev;
	struct node* next;
};
typedef struct node Node;

Node* header = NULL;
Node* trailer = NULL;
int size = 0;

void begin();
void initHeadTrail();
Node* createNode(int, Node*, Node*);
void addFirst(int);
void addLast(int);
void addBetween(int, Node*, Node*);
int removeFirst();
int removeLast();
int removeBetween(Node*);
void printList();

int main() {
	begin();

	free(header);
	free(trailer);
	return 0;
}

void begin() {
	initHeadTrail();

	while (true) {
		system("clear");
		printf("***********Doubly Linked List*******************\n");
		printf("0. Exit\n");
		printf("1. Add first\n");
		printf("2. Add last\n");
		printf("3. Remove first\n");
		printf("4. Remove last\n");
		printf("5. Print doubly linked list\n");
		printf("***********End Doubly Linked List****************\n");

		int choice, number;
		/* char s[50]; */
		printf("Enter(0 to exit): ");
		scanf("%d", &choice);
		/* getchar(); // get '/n' */

		switch (choice) {
		case 1:
			printf("Enter number: ");
			scanf("%d", &number);
			/* fgets(s, sizeof(s), stdin); */
			addFirst(number);
			break;
		case 2:
			printf("Enter number: ");
			scanf("%d", &number);
			addLast(number);
			break;
		case 3:
			printf("I just removed (first): %d\n", removeFirst());
			break;
		case 4:
			printf("I just removed (last): %d\n", removeLast());
			break;
		case 5:
			printList();
			break;
		case 0:
			return;
		}

		printf("Press any key to continue...");
		getchar(); getchar();
	}
}

void initHeadTrail() {
	header = createNode(0, NULL, NULL);
	trailer = createNode(0, header, NULL);
	header->next = trailer;
}

Node* createNode(int data, Node* prev, Node* next) {
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;

	/* newNode->data = (char*) malloc(strlen(data) + 1); */
	// here the format: char* strcpy(char* dst, const char* src);
	/* strcpy(newNode->data, data); */

	newNode->prev = prev;
	newNode->next = next;

	return newNode;
}

void addFirst(int data) {
	addBetween(data, header, header->next);
}

void addLast(int data) {
	addBetween(data, trailer->prev, trailer);
}

void addBetween(int data, Node* before, Node* after) {
	Node* newNode = createNode(data, before, after);
	
	before->next = newNode;
	after->prev = newNode;

	size++;
}

int removeFirst() {
	return (removeBetween(header->next));
}

int removeLast() {
	return (removeBetween(trailer->prev));
}

int removeBetween(Node* node) {
	int data = node->data;

	Node* prevNode = node->prev;
	Node* nextNode = node->next;

	prevNode->next = node->next;
	nextNode->prev = node->prev;

	node->prev = NULL;
	node->next = NULL;

	size--;
	free(node);
	return data;
}

void printList() {
	for (Node* travel = header->next; travel != trailer; travel = travel->next) {
		printf("Result: %d\n", travel->data);
	}
}
