#define _CRT_SECURE_NO_WARNINGS 1
#pragma warnig(disable : 6031) // scanf의 반환값을 warning c6031을 해제하기 위해 추가
#include <stdio.h>
#include <malloc.h>
#include<string.h>
#define MAX_N 10
#define MAX_M 30
int reduceTDM(int(*TDM)[MAX_M], int(*rTDM)[3], int N, int M, char* terms[]);
int main(void) {
	int N = 0, M = 0, TDM[MAX_N][MAX_M] = { 0 }, rTDM[MAX_N * MAX_M][3] = { 0 };
	char* terms[MAX_N] = { NULL }, temp[100];
	int i = 0, j = 0, len, count = 0;
	printf("TDM를 구성할 단어 개수 N과 단어목록을 입력하세요  : ");
	scanf("%d", &N);
	while (i < N) {
		scanf("%s", temp);
		//입력받은 문자열을 동적할당으로 terms 포인터 배열에 할당하기
		len = strlen(temp);
		if (len > 0) {
			char* strptr = (char*)malloc(sizeof(char) * (len + 1));
			strcpy(strptr, temp);
			terms[i] = strptr;
			i++;
		}
	}
	printf("\nTDM을 구성할 문서 개수 M을 입력하세요 : ");
	scanf("%d", &M);
	printf("\nTDM을 입력하세요(M X N 개 ) : \n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &TDM[i][j]);
		}
	}
	count = reduceTDM(TDM, rTDM, N, M, terms);
	printf("\n\ncount : %d \n", count);// 0이 아닌 원소 갯수(축소된 TDM의 행의 갯수) 출력 =>확인용
	return 0;
}

int reduceTDM(int(*TDM)[MAX_M], int(*rTDM)[3], int N, int M, char* terms[]) {
	int i = 0, j = 0, count = 0;
	// TDM축소 행렬 만들기
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (TDM[i][j] != 0) {
				rTDM[count][0] = i;
				rTDM[count][1] = j;
				rTDM[count][2] = TDM[i][j];
				count++;
			}
			
		}
	}
	// TDM 축소행렬 출력하기
	printf("\n\n[ TDM 축소 행렬]\n");
	for (i = 0; i < count; i++) {
		for (j = 0; j < 3; j++) {
			switch (j) {
			case 0:
				printf("%10s", terms[rTDM[i][j]]); break;
			case 1:
				printf(" 문서%-2d", rTDM[i][j] + 1); break;
			case 2: printf("%3d \n", rTDM[i][j]);
			}
		}

	}
	return count;// 0이 아닌 원소 갯수(축소된 TDM의 행의 갯수)
}

/*
5 오늘 데이터 날씨 순차 강아지
10
0 1 0 0 0 0 1 0 2 3
9 0 0 1 0 4 0 0 0 0
0 2 0 0 0 0 1 0 1 5
12 0 0 0 0 7 0 0 0 0
0 1 0 0 0 0 0 0 3 0
*/