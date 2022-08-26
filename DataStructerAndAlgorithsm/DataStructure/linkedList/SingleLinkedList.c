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

void addRandom(char *data, int index) {
	
}

char *removeFirst() {
	if (isEmpty()) {
		return NULL;
	}

	Node *tempNode = head;
	char *tempData = tempNode->data;

	if (size-- == 1) {
		head = head->next;
		tail = head;
	} else {
		head = head->next;
	}
	
	free(tempNode);
	return tempData;
}

char *removeRandom(int index) {
	if (isEmpty()) {
		return NULL;
	}

	if (index == 0) {
		return (removeFirst());
	} else if (index > size) {
		return NULL;
	}

	int i = 0;
	Node *travel = head;
	while (i++ < index - 1) {
		travel = travel->next;
	}

	Node *tempNode = travel->next;
	char *tempData = tempNode->data;

	travel->next = tempNode->next;
	size--;

	free(tempNode);

	return tempData;
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

	// remove first
	printf("Tao vua vua xoa(remove first): %s\n", removeFirst());
	printf("Tao vua vua xoa(remove first): %s\n", removeFirst());

	// remove random
	printf("Tao vua xoa(remove random): %s\n", removeRandom(2));

	printList();

	return 0;
}
