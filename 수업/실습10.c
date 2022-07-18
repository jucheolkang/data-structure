#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_N 10
typedef struct CDLNode {
	int number;
	int step;
	bool ch;
	struct CDLNode* llink, * rlink;
}CDLNode;

typedef struct CDLLIst {
	CDLNode* head;
}CDLList;

CDLList* createCDLList(void) {
	CDLList* CDL = (CDLList*)malloc(sizeof(CDLList));
	CDL->head = NULL;
	return CDL;
}
CDLNode* insertCDLNode(CDLList* CDL, CDLNode* pre, int X, int step) {
	CDLNode* newNode = (CDLNode*)malloc(sizeof(CDLNode));
	newNode->number = X;
	newNode->step = step;
	//newNode->ch = false;
	if (CDL->head == NULL) {
		CDL->head = newNode;
		newNode->rlink = newNode;
		newNode->llink = newNode;
	}
	else {
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		CDL->head->llink = newNode;
	}
	return newNode;
}

void deleteNode(CDLList* DL, CDLNode* delNode) {
	if (DL->head == NULL) return; //공백 리스트인 경우 종료
	else if (delNode == NULL) return;//찾으려고 하는 노드가 없는경우
	else {
		delNode->llink->rlink = delNode->rlink;
		delNode->rlink->llink = delNode->llink;
		free(delNode);
	}
}
CDLNode* searchNode(CDLList* CDL, const char* X) {// 노드에서 값 찾기
	CDLNode* p = CDL->head;
	while (p != NULL) {
		if (strcmp(p->number, X) == 0) return p;
		else p = p->rlink;
	}
	return p;
}
int main(void) {
	int i, n, step, move[MAX_N] = { 0 };
	int count = 0;
	CDLNode* p;
	CDLList* CDL = createCDLList();
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf_s("%d", &move[i]);
	p = CDL->head;
	for (i = 0; i < n; i++) p = insertCDLNode(CDL, p, i + 1, move[i]);
	p = CDL->head; printf("%5d", p->number); p->ch = true;

	do {
		step = p->step;
		if (step > 0) {
		for (i = 0; i < step; i++) p = p->rlink;
		while(p->ch == true) {
			p = p->rlink;
		}
		}
		else { 
			for (i = step; i < 0; i++) p = p->llink; 
			while(p->ch == true) {
				p = p->llink;
			}
		}
		printf(" %5d ", p->number);
		p->ch = true;
		count++;
	} while (count < n - 1);
	printf("\n");
	return 1;

}
