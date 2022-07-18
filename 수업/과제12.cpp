#include<stdio.h>
#include<stdlib.h>
typedef char element;
typedef struct LinkedDequeNode {
	element data;
	struct LinkedDequeNode* llink, * rlink;
}DQNode;

typedef struct LinkedDeque {
	DQNode* front, * rear;
}Deque;

int isEmpty(Deque* LDQ) {
	if (LDQ->front == NULL) {
		printf("\n Linked Queue is empty! \n");
		return 1;
	}
	else return 0;
}

Deque* createLinkedDeque(void) {
	Deque* LDQ = (Deque*)malloc(sizeof(Deque));
	LDQ->front = NULL;
	LDQ->rear = NULL;
	return LDQ;
}
void insertFront(LinkedDeque* LDQ, element item) {
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (LDQ->front == NULL) {
		LDQ->front = newNode;
		LDQ->front = newNode;
		LDQ->rear = newNode;
		newNode->rlink = NULL;
		newNode->llink = NULL;
	}
	else {
		LDQ->front->llink = newNode;
		newNode->rlink = LDQ->front;
		newNode->llink = NULL;
		LDQ->front = newNode;
	}
}
void insertRear(LinkedDeque* LDQ, element item) {
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (LDQ->front == NULL) {
		LDQ->front = newNode;
		LDQ->front = newNode;
		LDQ->rear = newNode;
		newNode->rlink = NULL;
		newNode->llink = NULL;
	}
	else {
		LDQ->rear->rlink = newNode;
		newNode->llink = LDQ->rear;
		newNode->rlink = NULL; 
		LDQ->rear = newNode;
	}
}
element deleteFront(LinkedDeque* LDQ) {
	DQNode* old = LDQ->front;
	element item;
	if (isEmpty(LDQ))return 0;
	else {
		item = old->data;
		if (LDQ->front->rlink == NULL) {
			LDQ->front = NULL;
			LDQ->rear = NULL;
		}
		else {
			LDQ->front = LDQ->front->rlink;
			LDQ->front->llink = NULL;
		}
		free(old);
		return item;
	}
}
element deleteRear(LinkedDeque* LDQ){
	DQNode* old = LDQ->rear;
	element item;
	if (isEmpty(LDQ))return 0;
	else {
		item = old->data;
		if (LDQ->rear->llink == NULL) {
			LDQ->rear = NULL;
			LDQ->front = NULL;
		}
		else {
			LDQ->rear = LDQ->rear->llink;
			LDQ->rear->rlink = NULL;
		}
		free(old);
		return item;
	}
}
void printDeque(LinkedDeque* LDQ) {
	DQNode* temp = LDQ->front;
	printf("DeQue : [");
	while (temp) {
		printf("%3c", temp->data);
		temp = temp->rlink;
	}
	printf(" ]\n");
}

int main(void) {
	Deque* LDQ = createLinkedDeque();
	element data;
	insertFront(LDQ, 'A'); printDeque(LDQ);
	insertFront(LDQ, 'B'); printDeque(LDQ);
	insertRear(LDQ, 'C'); printDeque(LDQ);
	data = deleteFront(LDQ); printDeque(LDQ);
	data = deleteRear(LDQ); printDeque(LDQ);
	insertRear(LDQ, 'D'); printDeque(LDQ);
	insertFront(LDQ, 'E'); printDeque(LDQ);
	insertFront(LDQ, 'F'); printDeque(LDQ);
	return 1;
}