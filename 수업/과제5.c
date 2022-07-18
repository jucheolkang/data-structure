#include <stdio.h>
#include <stdlib.h>
#define MAX_DEGREE 20
#define MAX(a,b)((a>b)?a:b)
typedef struct SparseMatrixTerm {
	int row;
	int col;
	int val;
}sparse_term;
typedef struct SparseMatrix {
	int NOT;
	int row_degree;
	int col_degree;
	sparse_term item[MAX_DEGREE];
}sparse_matrix;
sparse_matrix* createSparseMatrix(int N, int R, int C, sparse_term item[])
{
	sparse_matrix* SM = (sparse_matrix*)malloc(sizeof(sparse_matrix));
	if (SM != NULL) {
		SM->NOT = N; 
		SM->row_degree = R; SM->col_degree = C;
		for (int i = 0; i < SM->NOT; i++) {
			SM->item[i].row = item[i].row; SM->item[i].col = item[i].col; SM->item[i].val = item[i].val;
		}

	}
	return SM;
}

void printSparseMatrix(sparse_matrix* SM) {

	for (int i = 0; i < SM->NOT; i++) {
		printf("\n[%3d %3d %3d]", SM->item[i].row, SM->item[i].col, SM->item[i].val);
	}
	getchar();
}

sparse_matrix* addSparseMatrix(sparse_matrix* sparse1, sparse_matrix* sparse2) {
	sparse_matrix* sparse3 = (sparse_matrix*)malloc(sizeof(sparse_matrix));
	if (sparse3 != NULL) {
		sparse3->NOT = 13;
		sparse3->row_degree = MAX(sparse1->row_degree, sparse2->row_degree);
		sparse3->col_degree = MAX(sparse1->col_degree, sparse2->col_degree);
		int p = 0;
		for (int i = 0; i < sparse3->NOT; i++) {
			if (sparse1->item[i].row == sparse2->item[i].row && sparse1->item[i].col == sparse2->item[i].col) {
				sparse3->item[p].row = sparse1->item[i].row;
				sparse3->item[p].col = sparse1->item[i].col;
				sparse3->item[p].val = sparse1->item[i].val + sparse2->item[i].val;
				p++;
			}
			else {
				sparse3->item[p].row = sparse1->item[i].row;
				sparse3->item[p].col = sparse1->item[i].col;
				sparse3->item[p].val = sparse1->item[i].val;
				p++;
				sparse3->item[p].row = sparse2->item[i].row;
				sparse3->item[p].col = sparse2->item[i].col;
				sparse3->item[p].val = sparse2->item[i].val;
				p++;

			}
		}
	}
	return sparse3;
}

int main(void)
{
	sparse_term itemA[] = { {0,2,2},{0,6,12},{1,4,7}, {2,0,23}, {3,3,31},
					  {4,1,14},{4,5,25},{5,6,6},{6,0,52}, {7,4,11} };
	sparse_matrix* SA = createSparseMatrix(10, 8, 7, itemA);
	printSparseMatrix(SA);
	sparse_term itemB[] = { {0,2,23,},{0,6,52},{1,4,14}, {2,0,2}, {3,3,31},
					  {4,1,7},{4,7,11},{5,4,25},{6,0,12}, {6,5,6} };
	sparse_matrix* SB = createSparseMatrix(10, 8, 7, itemB);
	printSparseMatrix(SB);
	sparse_matrix* SC = addSparseMatrix(SA, SB);
	printSparseMatrix(SC);
	return 1;
}
