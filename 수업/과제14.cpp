#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct BtreeNode {
	element data;
	struct BtreeNode* left, * right;
}BtreeNode;

element Fordersize = 0;

BtreeNode* createBtreeNode(element data) {
	BtreeNode* newNode = (BtreeNode*)malloc(sizeof(BtreeNode));
	newNode->data = data; 
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
BtreeNode* makeBtree(BtreeNode* N, BtreeNode* left, BtreeNode* right) {
	if (N != NULL) {
		N->left = left; 
	    N->right = right; }
	return N;
}
void destroyBtreeNode(BtreeNode* N) {
	free(N);
}
void destroyBtree(BtreeNode* N) {
	if (N == NULL) return;
	destroyBtree(N->left); destroyBtree(N->right); destroyBtreeNode(N);
}
element getFolderSizePreorder(BtreeNode* N) {
	if (N != NULL) { 
		getFolderSizePreorder(N->left); 
		getFolderSizePreorder(N->right); 
		Fordersize += N->data;
		return Fordersize; }
}

int  main(void) {
	BtreeNode* F11 = createBtreeNode(120); BtreeNode* F10 = createBtreeNode(55);
	BtreeNode* F9 = createBtreeNode(100); BtreeNode* F8 = createBtreeNode(200);
	BtreeNode* F7 = createBtreeNode(68); BtreeNode* F6 = createBtreeNode(40);
	BtreeNode* F5 = createBtreeNode(15); BtreeNode* F4 = createBtreeNode(2);
	BtreeNode* F3 = createBtreeNode(10); BtreeNode* F2 = createBtreeNode(0);
	BtreeNode* F1 = createBtreeNode(0);

	BtreeNode* N4 = makeBtree(F7,F10,F11); BtreeNode* N3 = makeBtree(F4, F8, F9);
	BtreeNode* N2 = makeBtree(F3, F6, F7); BtreeNode* N1 = makeBtree(F2, F4, F5);
	BtreeNode* N0 = makeBtree(F1, N1, N2);

	getFolderSizePreorder(N0);
	printf("%d", Fordersize);
	destroyBtree(N0);
	return 1;
}