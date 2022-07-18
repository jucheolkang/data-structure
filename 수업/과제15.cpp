#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct BSTNode {
	element data;
	struct BSTNode* left; struct BSTNode* right;
}BSTNode;

BSTNode* createNode(element data) {
	BSTNode* N = (BSTNode*)malloc(sizeof(BSTNode));
	N->data = data; N->left = NULL; N->right = NULL;
	return N;
}

void destroyNode(BSTNode* N) {
	free(N);
}

void destroyTree(BSTNode* T) {
	if (T == NULL) return;
	destroyTree(T->left); destroyTree(T->right); destroyNode(T);
}
 BSTNode* searchNode(BSTNode* T, element data){
	 BSTNode* p = T;
	 while (p != NULL) {
		 if (data < p->data) p = p->left;
		 else if (data == p->data) return p;
		 else p = p->right;
	 }
	 printf("\n ã�� Ű�� �����ϴ�.");
	 return p;
 }

void insertNode(BSTNode* T, BSTNode* C) {
	if (T->data < C->data) {
		if (T->right == NULL) T->right = C;
		else insertNode(T->right, C);
	}
	else if (T->data > C->data) {
		if (T->left == NULL)T->left = C;
		else insertNode(T->left, C);
	}
}

 BSTNode* removeNode(BSTNode* T, BSTNode* Parent, element data){
	 BSTNode* p, * succ, * succ_parent;
	 BSTNode* child;
	 p = T;
	 while ((p != NULL) && (p->data != data)) {
		 Parent = p;
		 if (data < p->data) { p = p->left; }
		 else p = p->right;
	 }
	 // ������ ��尡 ���� ���
	 if (p == NULL) {
		 printf("\n ã�� Ű�� ���� Ʈ���� �����ϴ�!!");
		 return 0;
	 }
	 //������ ��尡 �ܸ� ����� ���
	 if ((p->left == NULL) && (p->right == NULL)) {
		 if (Parent != NULL) {
			 if (Parent->left == p) { Parent->left = NULL; }
			 else Parent->right = NULL;
		 }
		 else T = NULL;
	 }
	 //������ ��尡 �ڽ� ��带 �� �� ���� ���
	 else if ((p->left == NULL) || (p->right == NULL)) {
		 if (p->left != NULL) child = p->left;
		 else child = p->right;

		 if (Parent != NULL) {
			 if (Parent->left == p)Parent->left = child;
			 else Parent->right = child;
		 }
		 else T = child;
	 }
	 // ������ ��尡 �ڽ� ��带 �� �� ���� ���
	 else {
		 succ_parent = p;
		 succ = p->left;
		 while (succ->right != NULL) {
			 succ_parent = succ;
			 succ = succ->right;
		 }
		 if (succ_parent->left == succ) succ_parent->left = succ->left;
		 else succ_parent->right = succ->left;
		 p->data = succ->data;
		 p = succ;
	 }
	 free(p);
 }

void printBSTInorder(BSTNode* N) {
	if (N == NULL)return;
	printBSTInorder(N->left); printf("%3d\t", N->data); printBSTInorder(N->right);
}
int main(void) {
	BSTNode* T = createNode(123);
	BSTNode* N = NULL;
	insertNode(T, createNode(22)); insertNode(T, createNode(9918));
	insertNode(T, createNode(424)); insertNode(T, createNode(17));
	insertNode(T, createNode(3)); insertNode(T, createNode(98));
	insertNode(T, createNode(34)); insertNode(T, createNode(760));
	insertNode(T, createNode(317)); insertNode(T, createNode(1));
	printBSTInorder(T);  printf("\n");

	N = removeNode(T, NULL, 98);
	destroyNode(N);
	printBSTInorder(T); printf("\n");

	if ((N = searchNode(T, 111)) == NULL) 
		insertNode(T, createNode(111));
	printBSTInorder(T); printf("\n");

	destroyTree(T);
	return 1;
}