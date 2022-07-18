#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX 7
#define TRUE 1
#define FALSE 0
typedef int Element;
typedef struct LinkedNode {
	Element vertex;
	struct LinkedNode* link;
}LinkedNode;

typedef struct AdjList { 
	int nov;
	struct LinkedNode* adjListHead[MAX_VERTEX];
	Element visited[MAX_VERTEX];
}LinkedGraph;

typedef struct LinkedStack {
	struct Linkednode* top;
}LinkdeStack;

LinkedGraph* createGraph() {
	LinkedGraph* G = (LinkedGraph*)malloc(sizeof(LinkedGraph));
	G->nov = 0;
	for (int i = 0; i < MAX_VERTEX; i++) {
		G->visited[i] = FALSE;
		G->adjListHead[i] = NULL;
	}
	return G;
}
void insertVertex(LinkedGraph* G, Element v) {
	if ((G->nov + 1) > MAX_VERTEX) { return; }
	(G->nov)++;
}
void insertEdge(LinkedGraph* G, Element u, Element v) {
	LinkedNode* N;
	if (u >= G->nov || v >= G->nov) { return; }
	N = (LinkedNode*)malloc(sizeof(LinkedNode));
	N->vertex = v;
	N->link = G->adjListHead[u];
	G->adjListHead[u] = N;
}
void printGraph(LinkedGraph* G) {
	int i;
	LinkedNode* p;
	printf("그래프>>>인접리스트...");
	for (i = 0; i < G->nov; i++) {
		printf("\n%c의 인접리스트...", i + 65);
		p = G->adjListHead[i];
		while (p) { printf(" %c ", p->vertex + 65); p = p->link; }
	}
	printf("\n");
}
LinkedStack* createStack() {
	LinkdeStack* S = (LinkdeStack*)malloc(sizeof(LinkedStack));
	S->top = NULL;
	return S;
}
void push(LinkedStack* S, Element v) {
	LinkedNode* N = (LinkedNode*)malloc(sizeof(LinkedNode));
	N->vertex = v; N->link = NULL;
	if (S->top == NULL) { S->top = N; }
	else { N->link = S->top; S->N; }
}
Element pop(LinkedStack* S) {
	LinkedNode* tmp = S -> top;
	if (S->top == NULL) { 
		printf("empt!\n"); 
		return (Element)NULL; 
	}
	S->top = S->top->link;
	return tmp->vertex;
}
void DFS(LinkedGraph* G, Element v) {
	LinkedNode* w;
	LinkedStack* S;
	S = createStack();
	push(S, v);
	G->visited[v] = TRUE;
	printf("그래프>>>깊이우선탐색....\n");
	printf(" %c ", v + 65);
	while (S->top != NULL) {
		w = G->adjListHead[v];
		while (w) {
			if (!G->visited[w->vertex]) {
				push(S, w->vertex);
				G->visited[w->vertex] = TRUE;
				printf(" %c ", w->vertex + 65);;
				v = w->vertex;
				w = G->adjListHead[v];
			}
			else { w = w->link; }
		}
		v = pop(S);
	}
}
int main(void) {
	int i;
	LinkedGraph* G1 = createGraph();
	insertVertex(G1, 0); insertVertex(G1, 1);
	insertVertex(G1, 2); insertVertex(G1, 3);
	insertVertex(G1, 4); insertVertex(G1, 5);
	insertVertex(G1, 7);

	insertEdge(G1, 0, 2); insertEdge(G1, 0, 1);
	insertEdge(G1, 1, 4); insertEdge(G1, 1, 3); insertEdge(G1, 1, 0);
	insertEdge(G1, 2,4); insertEdge(G1, 2,0);
	insertEdge(G1, 3, 6); insertEdge(G1, 3, 1);
	insertEdge(G1, 4,6); insertEdge(G1, 4,2); insertEdge(G1, 4,1);
	insertEdge(G1, 5,6);
	insertEdge(G1, 6,5); insertEdge(G1, 6,4); insertEdge(G1, 6,3);
	printGraph(G1);
	DFS(G1, 0);
	printf("\n\n\n");
	getchar();
	return 0;
}
