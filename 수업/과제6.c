#define _CRT_SECURE_NO_WARNINGS 1
#pragma warnig(disable : 6031) // scanf�� ��ȯ���� warning c6031�� �����ϱ� ���� �߰�
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
	printf("TDM�� ������ �ܾ� ���� N�� �ܾ����� �Է��ϼ���  : ");
	scanf("%d", &N);
	while (i < N) {
		scanf("%s", temp);
		//�Է¹��� ���ڿ��� �����Ҵ����� terms ������ �迭�� �Ҵ��ϱ�
		len = strlen(temp);
		if (len > 0) {
			char* strptr = (char*)malloc(sizeof(char) * (len + 1));
			strcpy(strptr, temp);
			terms[i] = strptr;
			i++;
		}
	}
	printf("\nTDM�� ������ ���� ���� M�� �Է��ϼ��� : ");
	scanf("%d", &M);
	printf("\nTDM�� �Է��ϼ���(M X N �� ) : \n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &TDM[i][j]);
		}
	}
	count = reduceTDM(TDM, rTDM, N, M, terms);
	printf("\n\ncount : %d \n", count);// 0�� �ƴ� ���� ����(��ҵ� TDM�� ���� ����) ��� =>Ȯ�ο�
	return 0;
}

int reduceTDM(int(*TDM)[MAX_M], int(*rTDM)[3], int N, int M, char* terms[]) {
	int i = 0, j = 0, count = 0;
	// TDM��� ��� �����
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
	// TDM ������ ����ϱ�
	printf("\n\n[ TDM ��� ���]\n");
	for (i = 0; i < count; i++) {
		for (j = 0; j < 3; j++) {
			switch (j) {
			case 0:
				printf("%10s", terms[rTDM[i][j]]); break;
			case 1:
				printf(" ����%-2d", rTDM[i][j] + 1); break;
			case 2: printf("%3d \n", rTDM[i][j]);
			}
		}

	}
	return count;// 0�� �ƴ� ���� ����(��ҵ� TDM�� ���� ����)
}

/*
5 ���� ������ ���� ���� ������
10
0 1 0 0 0 0 1 0 2 3
9 0 0 1 0 4 0 0 0 0
0 2 0 0 0 0 1 0 1 5
12 0 0 0 0 7 0 0 0 0
0 1 0 0 0 0 0 0 3 0
*/