#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct DLNode {
	char data[10];
	struct DLNode* llink, * rlink;
}DLNode;// 이중연결리스트의 구조체 생성

typedef struct DLList {
	struct DLNode* head;
	}DLList;// 리스트 헤드 생성

DLList* createDLList(void) {// 헤드 만들기
	DLList* DL = (DLList*)malloc(sizeof(DLList));
	DL->head = NULL;
	return DL;
}
DLNode* searchNode(DLList* DL, const char* X) {// 노드에서 값 찾기
	DLNode* p = DL->head;
	while (p != NULL) {
		if (strcmp(p->data, X) == 0) return p;
		else p = p->rlink;
	}
	return p;
}

void insertNode(DLList* DL,DLNode* preNode, const char* X) {// 노드 만들기
	DLNode* newNode = (DLNode*)malloc(sizeof(DLNode));
	strcpy(newNode->data, X);
	if (DL->head == NULL) {
		newNode->rlink = NULL;
		newNode->llink = NULL;
		DL->head = newNode;
	}
	else {
		newNode->rlink = preNode->rlink;
		preNode->rlink = newNode;
		newNode->llink = preNode;
		if (newNode->rlink != NULL) newNode->rlink->llink = newNode;
		
	}
}


void appendNode(DLList * DL, const char* X) {
	DLNode* newNode = (DLNode*)malloc(sizeof(DLNode));
	DLNode* temp = DL->head;
	newNode->rlink = NULL;
	strcpy(newNode->data, X);
	if (DL->head == NULL) {
		DL->head = newNode;
		return;
	}
	else {
		temp = DL->head;
		while (temp->rlink != NULL) {
			temp = temp->rlink;
		}
		temp->rlink = newNode;
	}
}

void deleteNode(DLList* DL, DLNode* delNode) {
	if (DL->head == NULL) return; //공백 리스트인 경우 종료
	else if (delNode == NULL) return;//찾으려고 하는 노드가 없는경우
	else {
		delNode->llink->rlink = delNode->rlink;
		delNode->rlink->llink = delNode->llink;
		free(delNode);
	}
}
void printDLList(DLList* DL) {
	DLNode* p = DL->head;
	if (p == NULL) return;
	printf("DL = [");
	while (p != NULL) {
		printf("%s", p->data);
		if (p->rlink != NULL) {
		printf(",");
		}
		p = p->rlink;
		
	}
	printf("]\n");
}

int main(void) {
	DLList* DL;
	DL= createDLList();
	insertNode(DL, NULL, "월요일");
	printDLList(DL);
	insertNode(DL, searchNode(DL, "월요일"), "수요일");
	printDLList(DL);
	appendNode(DL, "금요일");
	printDLList(DL);
	deleteNode(DL, searchNode(DL, "수요일"));
	printDLList(DL);
	return 1;
}