#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b)((a>b?a:b))
typedef int element;
typedef struct Node {
    element key;
    struct Node* left;
    struct Node* right;
}Node;
Node* searchNode(Node* root, element x) {
    Node* p;
    int count = 0;
    p = root;
    while (p != NULL) {
        count++;
        if (x < p->key) p = p->left;
        else if (x == p->key) { printf("%d found\n", x); return p; }
        else p = p->right;
    }
    count++;
    printf("%d not found\n", x);
    return p;
}
void  printInorder(Node* root) {
    if (root) {
        printInorder(root->left);
        printf("%3d\t", root->key);
        printInorder(root->right);
    }
}
Node* rotateLL(Node* parent) {
    Node* child = parent->left;
    parent->left = child->right;
    child->right = parent;
    return child;
}
Node* rotateRR(Node* parent) {
    Node* child = parent->right;
    parent->right = child->left;
    child->left = parent;
    return child;
}
Node* rotateLR(Node* parent) {
    Node* child = parent->left;
    parent->left = rotateRR(child);
    return rotateLL(parent);
}
Node* rotateRL(Node* parent) {
    Node* child = parent->right;
    parent->right = rotateLL(child);
    return rotateRR(parent);
}

int getHeight(Node* p) {
    int height = 0;
    if (p != NULL) height = MAX(getHeight(p->left), getHeight(p->right)) + 1;
    return height;
}
int getBF(Node* p) {
    if (p == NULL) return 0;
    return getHeight(p->left) - getHeight(p->right);
}
Node* rebalance(Node** p) {
    int BF = getBF(*p);
    if (BF > 1) {
        if (getBF((*p)->left) > 0)*p = rotateLL(*p);
        else *p = rotateLR(*p);
    }
    else if (BF < -1) {
        if (getBF((*p)->right) < 0)*p = rotateRR(*p);
        else *p = rotateRL(*p);
    }
    return *p;
}
Node* insertAVLNode(Node** root, element x) {
    if (*root == NULL) {
        *root = (Node*)malloc(sizeof(Node));
        (*root)->key = x;
        (*root)->left = NULL;   (*root)->right = NULL;
    }
    else if (x < (*root)->key) {
        (*root)->left = insertAVLNode(&((*root)->left), x);
        *root = rebalance(root);
    }
    else if (x > (*root)->key) {
        (*root)->right = insertAVLNode(&((*root)->right), x);
        *root = rebalance(root);
    }
    else {
        printf("same key found\n");
        return NULL;
    }
    return *root;
}
int main(void) {
    Node* rootAVL = NULL;
    rootAVL = insertAVLNode(&rootAVL, 50);
    insertAVLNode(&rootAVL, 60);
    insertAVLNode(&rootAVL, 70);
    insertAVLNode(&rootAVL, 90);
    insertAVLNode(&rootAVL, 80);
    insertAVLNode(&rootAVL, 75);
    insertAVLNode(&rootAVL, 73);
    insertAVLNode(&rootAVL, 72);
    insertAVLNode(&rootAVL, 78);
    printf("AVL...");   printInorder(rootAVL);   printf("\n");
    searchNode(rootAVL, 70);   searchNode(rootAVL, 100);
    return 1;
}