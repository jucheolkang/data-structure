#include <stdio.h>
#include<stdlib.h>
typedef char element;
typedef struct BtreeNode {
	element data;
	struct BtreeNode* left, * right;
}BtreeNode;

BtreeNode* createBtreeNode(element data) {
	BtreeNode* newNode = (BtreeNode*)malloc(sizeof(BtreeNode));
	newNode->data = data; 
	newNode->left = NULL; 
	newNode->right = NULL;
	return newNode;
}

BtreeNode* makeBtree(BtreeNode* N, BtreeNode* left, BtreeNode* right) {
	if (N != NULL) { N->left = left; N->right = right; }
	return N;
}

void destroyBtreeNode(BtreeNode* N) {
	free(N);
}

void destroyBtree(BtreeNode* N) {
	if (N == NULL)return;
	destroyBtree(N->left); destroyBtree(N->right); destroyBtreeNode(N);
}

void printBtreePreorder(BtreeNode* N) {
	if (N != NULL) {
		printf("%3c", N->data); printBtreePreorder(N->left); printBtreePreorder(N->right);
	}
}

	void printBtreeInorder(BtreeNode * N) {
		if (N != NULL) {
			printBtreeInorder(N->left); printf("%3c", N->data); printBtreeInorder(N->right);
		}
	}

	void printBtreePostorder(BtreeNode* N) {
		if (N != NULL) {
			printBtreePostorder(N->left); printBtreePostorder(N->right); printf("%3c", N->data);
		}
	}

	int main(void) {
		BtreeNode* A = createBtreeNode('A'); BtreeNode* B = createBtreeNode('B');
		BtreeNode* C = createBtreeNode('C'); BtreeNode* D = createBtreeNode('D');
		BtreeNode* Div = createBtreeNode('/'); BtreeNode* Mul = createBtreeNode('*');
		BtreeNode* Sub = createBtreeNode('-'); 
		BtreeNode* N1 = makeBtree(Div, C, D); BtreeNode* N2 = makeBtree(Mul, A, B);
		BtreeNode* N0 = makeBtree(Sub, N2, N1);
		printf("Preorder : ");
		printBtreePreorder(N0); printf("\n");
		printf("Inorder : ");
		printBtreeInorder(N0); printf("\n");
		printf("Postorder : ");
		printBtreePostorder(N0); printf("\n");
		destroyBtree(N0);
		return 1;
	}