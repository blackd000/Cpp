#include <stdio.h>
#include <stdlib.h> // to use malloc 

struct node {
	char *data;
	struct node *next;
};
typedef struct node Node;

Node *head = NULL;
Node *tail = NULL;
int size = 0;

// access functions
bool isEmpty() {
	return (size == 0);
}

void printList() {
	int i = 0;
	for (Node *travel = head; travel != NULL; travel = travel->next, i++) {
		printf("%d Ket qua %s\n", i, travel->data);
	}
}

// update functions
// tao vung nho cho newNode roi gan data cho no
Node *createNode(char *data, Node *next) {
	Node *newNode = (Node *) (malloc(sizeof(Node)));
	newNode->data = data;
	newNode->next = next;

	return newNode;
}

void addFirst(char *data) {
	head = createNode(data, head);

	if (size++ == 0) {
		tail = head;
	}
}

void addLast(char *data) {
	Node *newNode = createNode(data, NULL);

	if (size++ == 0) {
		head = newNode;
	} else {
		tail->next = newNode;
	}

	tail = newNode;
}

int main() {
	char name[10][100] = {
		"Dong", "Tay", "Nam", "Bac", "Diep",
		"Giap", "Duc", "Dat"
	};

	// add first
	addFirst(name[0]);
	addFirst(name[1]);
	addFirst(name[2]);

	// add last
	addLast(name[3]);
	addLast(name[4]);
	addLast(name[5]);

	printList();

	return 0;
}
