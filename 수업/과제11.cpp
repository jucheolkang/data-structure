#include <stdio.h>
#include<stdlib.h>
typedef int eType;
typedef struct LinkedNode {
	eType item;
	struct LinkedNode* link;
} LinkedNode;

typedef struct LinkedStack {
	LinkedNode* top;
}LinkedStack;

LinkedStack* createLinkedStack() {
	LinkedStack* S = (LinkedStack*)malloc(sizeof(LinkedStack));
	if (S != NULL) S->top = NULL;
	return S;
}

void push(LinkedStack* S, eType item) {
	LinkedNode* temp = (LinkedNode*)malloc(sizeof(LinkedNode));
	temp->item = item;
	temp->link = S->top;
	S->top = temp;
}

eType pop(LinkedStack* S) {
	eType item;
	LinkedNode* temp = S->top;

	if (S->top == NULL) {
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {
		S->top = temp->link;
		free(temp);
	}
	return -1;
}
void printLinkedStack(LinkedStack* S) {
	LinkedNode* p = S->top;
	printf("\n STACK [");
	while (p) {
		printf("%d ", p->item);
		p = p->link;
	}
	printf("] \n");
}

int main(void) {
	LinkedStack* S = createLinkedStack();
	eType item;
	printLinkedStack(S);
	push(S, 1); printLinkedStack(S);
	push(S, 2); printLinkedStack(S);
	push(S, 3); printLinkedStack(S);
	push(S, 4); printLinkedStack(S);
	push(S, 5); printLinkedStack(S);
	push(S, 6); printLinkedStack(S);
	item = pop(S); printLinkedStack(S);
	item = pop(S); printLinkedStack(S);
	item = pop(S); printLinkedStack(S);
	item = pop(S); printLinkedStack(S);
	item = pop(S); printLinkedStack(S);
	item = pop(S); printLinkedStack(S);
	return 1;
}
