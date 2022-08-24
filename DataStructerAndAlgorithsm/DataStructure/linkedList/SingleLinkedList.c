#include <stdio.h>
#include <stdlib.h> // to use malloc 

struct node {
	char *data;
	node *next;
};
typedef node Node;

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
void addFirst(char *data) {
	// tao vung nho cho newNode roi gan data cho no
	Node *newNode = (Node *) (malloc(sizeof(Node)));
	newNode->data = data;
	newNode->next = head;

	head = newNode;

	if (size++ == 0) {
		tail = head;
	}
}

void addLast(char *data) {
	Node *newNode = (Node *) (malloc(sizeof(Node)));
	newNode->data = data;
	newNode->next = NULL;

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

	// add last
	addLast(name[2]);
	addLast(name[3]);

	printList();

	return 0;
}
