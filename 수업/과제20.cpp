#include<stdio.h>
#include<stdlib.h>
#define INF 10000
#define MAX_VERTICES 5
int distance[MAX_VERTICES];
int s[MAX_VERTICES];

int weight[MAX_VERTICES][MAX_VERTICES] = {
   {0,10,5,INF,INF},
   {INF,0,2,1,INF},
   {INF,3,0,9,2},
   {INF,INF,INF,0,4},
   {7,INF,INF,6,0},
};

int nextVertex(int n) {
    int i, min, minPos;
    min = INF;
    minPos = -1;
    for (i = 0; i < n; i++)
        if ((distance[i] < min) && !s[i]) {
            min = distance[i];
            minPos = i;
        }
    return minPos;
}

int printStep(int step) {
    int i;
    printf("\n %3d 단계 : S={", step);
    for (i = 0; i < MAX_VERTICES; i++)
        if (s[i] == (int)true)
            printf("%3c", i + 65);

    if (step < 1)printf(" }\t\t\t");
    else if (step < 4)printf(" } \t\t");
    else printf(" } \t");
    printf(" distance :[ ");
    for (i = 0; i < MAX_VERTICES; i++)
        if (distance[i] == INF)
            printf("%4c", '*');
        else printf("%4d", distance[i]);
    printf("%4c", ']');
    return ++step;
}

void Dijkstra_shortestPath(int start, int n) {
    int i, u, w, step = 0;
    for (i = 0; i < n; i++) {
        distance[i] = weight[start][i];
        s[i] = (int)false;
    }
    s[start] = true;
    distance[start] = 0;

    step = printStep(0);
    for (i = 0; i < n - 1; i++) {
        u = nextVertex(n);
        s[u] = true;
        for (w = 0; w < n; w++)
            if (!s[w])
                if (distance[u] + weight[u][w] < distance[w])
                    distance[w] = distance[u] + weight[u][w];
        step = printStep(step);
    }
}
int main(void) {
    int i, j;
    printf("\n************** 가중치 인접 행렬 *****************\n\n");
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            if (weight[i][j] == INF)
                printf("%4c", '*');
            else printf("%4d", weight[i][j]);
        }
        printf("\n\n");
    }
    printf("\n ********************** 다익스트라 최단 경로 구하기 *************************\n");
    Dijkstra_shortestPath(0, MAX_VERTICES);
    printf("\n\n");
    getchar();
    return 0;
}