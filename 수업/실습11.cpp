#include<stdio.h>
#include<malloc.h>
#define Stack_Size 5
typedef int eType;
typedef struct ArrayStack {
	int top;
	eType stack[Stack_Size];
}ArrayStack;;
ArrayStack* createArrayStack() {
	ArrayStack* S = (ArrayStack*)malloc(sizeof(ArrayStack));
	if (S != NULL) S->top = -1;
	return S;
}
void push(ArrayStack* S, eType item) {
	if (S->top == Stack_Size - 1) {
		printf("stack Full\n"); return;
	}
	S->stack[++(S->top)] = item;
}
eType pop(ArrayStack* S) {
	if (S->top == -1) {
		printf("stack Empty\n"); return -1;
	}
	return S->stack[(S->top)--];
}
void pirntArrayStack(ArrayStack* S) {
	if (S->top == -1) return;
	for (int i = 0; i < S->top + 1; i++) {
		printf("%3d", S->stack[i]);	}
	printf("\n");
}
int main(void) {
	ArrayStack* S = createArrayStack();
	eType item;
	push(S, 1); pirntArrayStack(S);
	push(S, 2); pirntArrayStack(S);
	push(S, 3); pirntArrayStack(S);
	push(S, 4); pirntArrayStack(S);
	push(S, 5); pirntArrayStack(S);
	push(S, 6); pirntArrayStack(S);
	item = pop(S); pirntArrayStack(S);
	item = pop(S); pirntArrayStack(S);
	item = pop(S); pirntArrayStack(S);
	item = pop(S); pirntArrayStack(S);
	item = pop(S); pirntArrayStack(S);
	item = pop(S); pirntArrayStack(S);
	return 1;
}