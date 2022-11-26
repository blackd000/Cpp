#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// - Initial:
// 		List l, l1, l2 
// 		l1 = P(X), l2 = Q(X): la 2 da thuc dau vao
// 		l = R(X) = P(X) + Q(X): la ket qua dau ra
//
// - Algorithm:
// 		FIND max and assign it to l and mark the other to mark
// 		INITIALIZE node run = l.head
// 		WHILE run's MU is not equal to mark's MU 
// 			SET run = runt->NEXT
// 		END WHILE
// 		WHILE run is not NULL
// 			SUM run's HSO and mark's HSO
// 		END WHILE

struct node {
	int HSO;
	int MU;
	struct node *NEXT;
};
typedef struct node Node;

struct list {
	Node *head;
	Node *tail;
};
typedef struct list List;

Node *createNode(int hso, int mu);
void createList(List &l);
void addTail(List &l, Node *p);
void nhap(List &l);
void cong(List &l, List l1, List l2);
void printDaThuc(List l);

int main() {
	List l, l1, l2;

	createList(l);
	createList(l1);
	createList(l2);

	nhap(l1);
	nhap(l2);

	cong(l, l1, l2);

	printDaThuc(l);

	return 0;
}

void createList(List &l) {
	l.head = l.tail = NULL;
}

Node *createNode(int hso, int mu) {
	Node *tempNode = new Node();

	tempNode->HSO = hso;
	tempNode->MU = mu;
	tempNode->NEXT = NULL;

	return tempNode;
}

void addTail(List &l, Node *p) {
	if (l.head == NULL) {
		l.head = l.tail = p;
		return;
	}

	l.tail->NEXT = p;
	l.tail = p;
}

void nhap(List &l) {
	int bac, heso;

	cout << "Nhap bac cua da thuc: ";
	cin >> bac;

	for (int i = bac; i > 0; i--) {
		cout << "Nhap he so cho x^" << i <<": ";
		cin >> heso;

		Node *p = createNode(heso, i);
		addTail(l, p);
	}
}

void cong(List &l, List l1, List l2) {
	Node *mark; // danh dau la min(l1.head, l2.head)
	Node *run; // de cong he so

	if (l1.head->MU > l2.head->MU) {
		l = l1;
		mark = l2.head;
	} else {
		l = l2;
		mark = l1.head;
	}

	// tim node run sao cho: run->MU == mark->MU
	run = l.head; 
	while (run->MU > mark->MU) {
		run = run->NEXT;
	}

	while (run != NULL) {
		run->HSO += mark->HSO;

		run = run->NEXT;
		mark = mark->NEXT;
	}
}

void printDaThuc(List l) {
	for (Node *travel = l.head; travel != NULL; travel = travel->NEXT) {
		cout << travel->HSO << "x^" << travel->MU;
		if (travel->NEXT != NULL) {
			cout << " + ";
		}
	}
	cout << endl;
}
