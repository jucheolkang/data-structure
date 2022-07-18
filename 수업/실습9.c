#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct DLNode {
	char data[10];
	struct DLNode* llink, * rlink;
}DLNode;// ���߿��Ḯ��Ʈ�� ����ü ����

typedef struct DLList {
	struct DLNode* head;
	}DLList;// ����Ʈ ��� ����

DLList* createDLList(void) {// ��� �����
	DLList* DL = (DLList*)malloc(sizeof(DLList));
	DL->head = NULL;
	return DL;
}
DLNode* searchNode(DLList* DL, const char* X) {// ��忡�� �� ã��
	DLNode* p = DL->head;
	while (p != NULL) {
		if (strcmp(p->data, X) == 0) return p;
		else p = p->rlink;
	}
	return p;
}

void insertNode(DLList* DL,DLNode* preNode, const char* X) {// ��� �����
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
	if (DL->head == NULL) return; //���� ����Ʈ�� ��� ����
	else if (delNode == NULL) return;//ã������ �ϴ� ��尡 ���°��
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
	insertNode(DL, NULL, "������");
	printDLList(DL);
	insertNode(DL, searchNode(DL, "������"), "������");
	printDLList(DL);
	appendNode(DL, "�ݿ���");
	printDLList(DL);
	deleteNode(DL, searchNode(DL, "������"));
	printDLList(DL);
	return 1;
}