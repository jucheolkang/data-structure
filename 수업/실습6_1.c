#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS 
//�ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode {
	char data[4];
	struct ListNode* Link;
}ListNode;

//����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct {
	ListNode* head;
}LinkedList_h;

// ���� ���� ����Ʈ�� �����ϴ� ����
LinkedList_h* createLinkedList_h(void) {
	LinkedList_h* L;
	L = (LinkedList_h* )malloc(sizeof(LinkedList_h));
	L->head = NULL; //���� ����Ʈ�̹Ƿ� null�� ����
	return L;
}

// ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freeLinkedList_h(LinkedList_h* L) {
	ListNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->Link;
		free(p);
		p = NULL;
	}
}

//���� ����Ʈ�� ������� ����ϴ� ����
void printList(LinkedList_h* L) {
	ListNode* p;
	printf("L = (");
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->Link;
		if (p != NULL) { printf(", "); }
	}
	printf(") \n");
}

// ù ��° ���� �����ϴ� ����
void insertFirstNode(LinkedList_h* L, char* x) {
	ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode)); // ������ �� ��� �Ҵ�
	strcpy(newNode->data, x); // �� ����� ������ �ʵ忡 x ����
	newNode->Link = L->head;
	L->head = newNode;
}

// ��带 pre �ڿ� �����ϴ� ����
void insertMiddleNode(LinkedList_h* L, ListNode* pre, char* x) {
	ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	strcpy(newNode->data, x);
	if (L == NULL) { // ���� ����Ʈ�� ���
		newNode->Link = NULL;// �� ��带 ù ��°���� ������ ���� ����
		L->head = newNode;
	}
	else if (pre == NULL) { // ���� ��ġ�� �����ϴ� ������ pre�� NULL�� ���
		L->head = newNode;// �� ��带 ù ��° ���� ����
	}
	else {
		newNode->Link = pre->Link;// ������ pre�� ��� �ڿ� �� ��� ����
		pre->Link = newNode;
	}
}

//������ ���� �����ϴ� ����
void insertLastNode(LinkedList_h* L, char* x) {
	ListNode* newNode;
	ListNode* temp;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	strcpy(newNode->data, x);
	newNode->Link = NULL;
	if (L->head == NULL) {// ���� ����Ʈ�� ������ ���
		L->head = newNode;//�� ��带 ����Ʈ�� ���� ���� ����
		return;
	}
	// ���� ����Ʈ�� ������ �ƴ� ���
	temp = L->head;
	while (temp->Link != NULL) { temp = temp->Link; }// ���� ����Ʈ�� ������ ��带 ã��
	temp->Link = newNode; // �� ��带 ������ ���(temp)�� ���� ���� ����
}

int main() {
	LinkedList_h* L;
	L = createLinkedList_h();
	printf("(1) ���� ����Ʈ �����ϱ�! \n");
	printList(L); 
	getchar();

	printf("(2) ����Ʈ�� [��] ��� �����ϱ�! \n");
	insertFirstNode(L, "��");
	printList(L); 
	getchar();

	printf("(3) ����Ʈ �������� [��] ��� �����ϱ�! \n");
	insertFirstNode(L, "��");
	printList(L); 
	getchar();

	printf("(4) ����Ʈ ù ��°�� [��] ��� �����ϱ�!\n");
	insertLastNode(L, "��");
	printList(L); 
	getchar();

	printf("(5) ����Ʈ ������ �����Ͽ� ���� ����Ʈ�� �����!\n");
	freeLinkedList_h(L);
	printList(L);
	getchar();
	return 0;
}