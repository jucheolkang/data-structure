#include<stdio.h>
#include<stdlib.h>
typedef char element;
typedef struct LinkedQueueNode {
	element data;
	struct LinkedQueueNode* link;
}QNode;
typedef struct LineQueue {
	QNode* front, * rear;
}LinkedQueue;

LinkedQueue* createLinkedQueue(void) {
	LinkedQueue* LQ = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	if (LQ != NULL) { LQ->front = NULL, LQ->rear = NULL; }
	return LQ;
}
void enQueue(LinkedQueue* LQ, element item) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode != NULL) { newNode->data = item, newNode->link = NULL; }
	if (LQ->front == NULL) { LQ->front = newNode, LQ->rear = newNode; }
	else {
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}
element deQueue(LinkedQueue* LQ) {
	QNode* tmp = LQ->front;
	element item;
	if (LQ->front == NULL)LQ->rear = NULL;
	else {
		item = tmp->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL) LQ->rear = NULL;
		free(tmp);
		return item;
	}
}
void printLinkedQueue(LinkedQueue* LQ) {
	QNode* p = LQ->front;
	while (p) {
		printf("%3c", p->data);
		p = p->link;
	}
	printf("\n");
}
int main(void) {
	LinkedQueue* LQ = createLinkedQueue();
	enQueue(LQ, 'A'); printLinkedQueue(LQ);
	enQueue(LQ, 'B'); printLinkedQueue(LQ);
	enQueue(LQ, 'C'); printLinkedQueue(LQ);
	deQueue(LQ); printLinkedQueue(LQ);
	deQueue(LQ); printLinkedQueue(LQ);
	deQueue(LQ); printLinkedQueue(LQ);

}
