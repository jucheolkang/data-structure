#include<stdio.h>
#include<stdlib.h>
#define MaxArraySize 30
#define MaxVertex 5

typedef struct AdjMatrix {
	unsigned nov;
	unsigned noe;
	int edge[MaxVertex][MaxVertex];
}ArrayGraph;

ArrayGraph * createGraph() {
	ArrayGraph* G = (ArrayGraph*)malloc(sizeof(ArrayGraph));
	G->nov = 0;// 노드의 개수(vertex의 개수)
	G->noe = 0;// edge의 개수
	return G;
}

void insertVertex(ArrayGraph* G, int v) {
	if (G->nov + 1 > MaxVertex) {
		printf("정점 갯수 초과\n"); return;
	}
	(G->nov)++;
}

void insertEdge(ArrayGraph* G, int u, int v, unsigned w) {
	if (u > (G->nov) - 1 || v > (G->nov) - 1) {
		printf("정점 번호 없음\n"); return;
	}
	//G->edge[u][v] = 1; 
	G->edge[u][v] = w;
	(G->noe)++;
}

void deleteVertex(ArrayGraph* G, int v) {}

void deleteEdege(ArrayGraph* G, int u, int v) {}

void printGraph(ArrayGraph* G) {
	int i, j;
	printf("그래프(정점갯수 : %2d, 간선갯수 %2d)\n\n", G->nov, G->noe);
	printf("인접 행렬!\n\n");
	for (i = 0; i < G->nov; i++) {
		printf("정점 번호 : %d\t", i);
		for (j = 0; j < G->nov; j++) {
			printf("%3d", G->edge[i][j]);
		}
		printf("\n");
	}
}

int main() {
	ArrayGraph* G1 = createGraph();
	for (int i = 0; i < MaxVertex; i++) {
		for (int j = 0; j < MaxVertex; j++) {
			G1->edge[i][j] = 0;
		}
	}
	insertVertex(G1, 0); insertVertex(G1, 1);
	insertVertex(G1, 2); insertVertex(G1, 3);

	insertEdge(G1, 0, 1, 1); insertEdge(G1, 0, 3, 3); 
	insertEdge(G1, 1, 0, 1); insertEdge(G1, 1, 2, 2); insertEdge(G1, 1, 3, 3);
	insertEdge(G1, 2,1,1); insertEdge(G1, 2,3,2);
	insertEdge(G1, 3, 0, 1); insertEdge(G1, 3, 1, 2); insertEdge(G1, 3, 2, 3);
	printGraph(G1);
	return 0;
}