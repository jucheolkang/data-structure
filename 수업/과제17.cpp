#include <stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 100

typedef struct MaxPriorityQueue {
	int elem[MAX_ELEMENT];
	int size;
	}MaxPQueue;

void insertMaxPQueue(MaxPQueue* PQ, int val) {
	int i;
	PQ->size = PQ->size + 1;
	i = PQ->size;
	while ((i != 1) && (val > PQ->elem[i / 2])) {
		PQ->elem[i] = PQ->elem[i / 2];
		i /= 2;
	}
	PQ->elem[i] = val;
} // 삽입함수

int removeMaxPQueue(MaxPQueue* PQ) {
	MaxPQueue* h = PQ;
	int parent, child;
	int item, temp;
	item = h->elem[1];
	temp = h->elem[h->size];
	h->size = h->size - 1;
	parent = 1;
	child = 2;
	while (child <= h->size) {
		if ((child < h->size) && (h->elem[child]) < h->elem[child + 1])
			child++;
		if (item >= h->elem[child]) break;
		else {
			h->elem[parent] = h->elem[child];
			parent = child;
			child = child * 2;
		}
	}
	h->elem[parent] = temp;
	return item;
} // 최대 항목 삭제 및 반환 함수

int findMaxPQueue(MaxPQueue* PQ) {
	MaxPQueue* h = PQ;
	int item;
	item = h->elem[1];
	return item;
} // 최대 항목 반환 함수
void displayMaxPQueue(MaxPQueue* PQ) {
	int item;
		item = removeMaxPQueue(PQ);
		printf("\n top : [%d]", item);
}

MaxPQueue* createMaxPQueue(void) {
	MaxPQueue* PQ = (MaxPQueue*)malloc(sizeof(MaxPQueue));
	PQ->size = 0;
	return PQ;
}

int main(void) {
	MaxPQueue* PQ = createMaxPQueue();
	insertMaxPQueue(PQ, 10);
	insertMaxPQueue(PQ,  45);
	insertMaxPQueue(PQ, 19);
	insertMaxPQueue(PQ, 11);
	insertMaxPQueue(PQ, 96);
	displayMaxPQueue(PQ);
	displayMaxPQueue(PQ);
	displayMaxPQueue(PQ);
	displayMaxPQueue(PQ);
	displayMaxPQueue(PQ);
	return 0;
}
