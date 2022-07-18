#include <stdio.h>
#include<stdlib.h>
#define MaArraySize 30
#define MaxVertex 5

typedef struct AdjListNode {
	int vertex;
	struct AdjListNode* link;
}AdjNode;

typedef struct AdjList {
	unsigned nov, noe; // 부호가 없는 정수형 (edge와 vertex의 개수)
	struct AdjListNode* head[MaxVertex];
}LinkedGraph;

LinkedGraph* createGraph() {
	LinkedGraph* G = (LinkedGraph*)malloc(sizeof(LinkedGraph));
	G->nov = 0;
	G->noe = 0;
	for (int i = 0; i < MaxVertex; i++) G->head[i] = NULL;
	return G;
}
void insertVertex(LinkedGraph* G, int v) {
// complete this funtion code
	if (G->nov+1 > MaxVertex) {
		printf("정점 갯수 초과\n"); return; 
	}
	(G->nov)++;
}
void insertEdge(LinkedGraph* G, int u, int v) {
	// complete this funtion code
	AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
	newNode->vertex = v;
	newNode->link = G->head[u];
	G->head[u] = newNode;
}
void deleteEdge(LinkedGraph* G, int u, int v) {
	// complete this funtion code
	AdjListNode* p = G->head[u];
	AdjListNode* q ;
	if (G->head[u] == NULL) return;
	if (G->head[u]->vertex == v) {
		free(G->head[u]);
		G->head[u] = NULL;
		return;
	}
	else {
		while (p->link->vertex != v) {
			p = p->link;
		}
		q = p->link;
		p->link = q->link;
		free(q);
		
	}
	
	
}
void printGraph(LinkedGraph* G) {
	// complete this funtion code
	int i;
	AdjListNode* p;
	for (i = 0; i < G->nov; i++) {
		printf("\n정점 %u의 인접 리스트", i );
		p = G->head[i];
		while (p) {
			printf("-> %u", p->vertex);
			p = p->link;
		}
	}
	
}

int main() {
	LinkedGraph* G1 = createGraph();
	insertVertex(G1, 0); insertVertex(G1, 1);
	insertVertex(G1, 2); insertVertex(G1, 3);

	insertEdge(G1, 0, 1); insertEdge(G1, 0, 3);
	insertEdge(G1, 1, 0); insertEdge(G1, 1,2); insertEdge(G1, 1,3);
	insertEdge(G1, 2, 1); insertEdge(G1, 2,3);
	insertEdge(G1, 3, 0); insertEdge(G1, 3, 1); insertEdge(G1, 3, 2);
	printGraph(G1);
	printf("\n\n\n\n");
	deleteEdge(G1, 2, 1);
	printGraph(G1);
	return 0;
}