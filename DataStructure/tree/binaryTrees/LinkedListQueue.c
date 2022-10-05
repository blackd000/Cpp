#include <stdio.h>
#include <stdlib.h>

struct binaryTreeNode {
	int data;
	struct binaryTreeNode *left;
	struct binaryTreeNode *right;
};
typedef struct binaryTreeNode BinaryTreeNode;

struct listNode {
	BinaryTreeNode *nodeTree;
	struct listNode *next;
};
typedef struct listNode ListNode;

struct queue {
	ListNode *front;
	ListNode *rear;
};
typedef struct queue Queue;

Queue *createQueue() {
	Queue *Q = (Queue *) malloc(sizeof(Queue));

	Q->front = Q->rear = NULL;

	return Q;
}

int isEmptyQueue(Queue *Q) {
	return (Q->front == NULL);
}

void enQueue(Queue *Q, BinaryTreeNode *data) {
	ListNode *tempNode = (ListNode*) malloc(sizeof(ListNode));

	tempNode->nodeTree = data;
	tempNode->next = NULL;

	if (Q->front == NULL) {
		Q->front = Q->rear = tempNode;
	} else {
		Q->rear->next = tempNode;
		Q->rear = tempNode;
	}
}

BinaryTreeNode *deQueue(Queue *Q) {
	if (isEmptyQueue(Q)) {
		printf("Exception: Queue is empty!!");
		return NULL;
	}

	ListNode *tempNode = Q->front;
	BinaryTreeNode *tempNodeTree = Q->front->nodeTree;

	Q->front = Q->front->next;

	free(tempNode);

	return tempNodeTree;
}

void deleteQueue(Queue *Q) {
	ListNode *temp = NULL;

	while (Q->front) {
		temp = Q->front;
		Q->front = Q->front->next;
		free(temp);
	}

	free(Q);
}

void printQueue(Queue *Q) {
	for (ListNode *traver = Q->front; traver; traver = traver->next) {
		printf("%d ", traver->nodeTree->data);
	}
}

/* int main() { */
/* 	Queue *queue = createQueue(); */

/* 	BinaryTreeNode *tree1 = (BinaryTree *) malloc(sizeof(BinaryTree)); */
/* 	tree1->data = 9; */

/* 	BinaryTree *tree2 = (BinaryTree *) malloc(sizeof(BinaryTree)); */
/* 	tree2->data = 14; */

/* 	enQueue(queue, tree1); */
/* 	enQueue(queue, tree2); */

/* 	printf("Tao vua moi xoa: %d\n", deQueue(queue)->data); */

/* 	/1* deleteQueue(queue); *1/ */

/* 	printQueue(queue); */

/* 	return 0; */
/* } */
