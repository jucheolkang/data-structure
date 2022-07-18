#include<stdio.h>// �ܼ� ���Ḯ��Ʈ���� ���  �����ϰ� Ž���ϱ�
#include<stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(suppress : 4996)
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
	L = (LinkedList_h*)malloc(sizeof(LinkedList_h));
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

//����Ʈ ��� p�� �����ϴ� ����
void deleteNode(LinkedList_h* L, ListNode* p) {
	ListNode* pre;// ������ ����� ������ ��带 ��Ÿ�� ������
	if (L->head == NULL) return;// ���� ����Ʈ��� ���� ���� �ߴ�
	if (L->head->Link == NULL) {// ����Ʈ�� ��尡 �� ���� �ִ� ���
		free(L->head);// ù��° ��带 �޸𸮿��� �����ϰ�
		L->head = NULL;//����Ʈ ���� �����͸� null�� ����
		return;
	}
	else if (p == NULL) return; // ������ ��尡 ���ٸ� ���� ���� �ߴ�
	else {
		pre = L->head;
		while (pre->Link != p) {
			pre = pre->Link;
		}
		pre->Link = p->Link;// ������ ��� p�� ������ ���� ���� ��带 ����
		free(p);//���� ����� �޸� ����
	}
}

//����Ʈ���� x��带 Ž���ϴ� ����
ListNode* searchNode(LinkedList_h * L, char* x ){
	ListNode* temp;
	temp = L->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->Link;
	}
	return temp;
}

// ����Ʈ�� ��� ������ �������� �ٲٴ� ����
void reverse(LinkedList_h* L) {
	ListNode* p;
	ListNode* q;
	ListNode* r;

	p = L->head;// ������ p�� ù ��° ��忡 ����
	q = NULL;
	r = NULL;

	// ����Ʈ�� ù ��° ������ ��ũ�� ���� ���� ���� �̵��ϸ鼭 ��� ���� ������ �ٲ�

	while (p != NULL) {
		r = q;
		q = p;
		p = p->Link;
		q->Link = r;
	}
	L->head = q;
}

int main() {
	LinkedList_h* L;
	ListNode* p;
	L = createLinkedList_h(); // ���� ����Ʈ ����
	printf("(1) ����Ʈ�� [��], [��], [��] ��� �����ϱ�! \n");
	insertLastNode(L, "��"); insertLastNode(L, "��"); insertLastNode(L, "��");
	printList(L); getchar();

	printf("(2) ����Ʈ���� [��] ��� Ž���ϱ� \n");
	p = searchNode(L, "��");
	if (p == NULL) printf("ã�� �����Ͱ� �����ϴ�.\n");
	else printf("[%s]�� ã�ҽ��ϴ�. \n", p->data);
	getchar();

	printf("(3) ����Ʈ���� [��] �ڿ� [��] ��� �����ϱ�! \n");
	insertMiddleNode(L, p, "��");
	printList(L); getchar();

	printf("(4) ����Ʈ���� [��] ��� �����ϱ�\n");
	p = searchNode(L, "��"); // ������ ��� ��ġ p�� ã��
	deleteNode(L, p); //������ p��� ����
	printList(L); getchar();
	printf("(5) ����Ʈ ������ �������� �ٲٱ�! \n");
	reverse(L);
	printList(L);

	freeLinkedList_h(L); //����Ʈ �޸� ����
	getchar();

	return 0;
}