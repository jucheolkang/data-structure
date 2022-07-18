/*#include<stdio.h>
void main() {

3_1 실습
	int i, sale[4] = {157, 209, 251, 312};
	for (i = 0; i < 4; i++) {
		printf("\n addres : %u sale[%d] = %d", &sale[i], i, sale[i]);
	}
	getchar();*/

	/*
	3_2 실습
	int i, n = 0, * ptr;
	int sale[2][4] = { {63, 84, 140, 130},{157, 209, 251,312} };// 2차원 배열 초기화
	ptr = &sale[0][0];
	for (i = 0; i < 8; i++) {
		printf("\n address : %u sale %d = %d", ptr, i, *ptr);
		ptr++;
	}
	getchar();*/

	/*3_3 실습
	int i, n = 0, * ptr;
	int sale[2][2][4] = { {{63,84,140,130},{157,209,251,312}},{{59,80,130,135},{149,187,239,310}} };
	ptr = &sale[0][0][0];
	for (i = 0; i < 16; i++) {
		printf("\n address: %u sale %2d = %3d", ptr, i, *ptr);
		ptr++;
	}
	getchar();


}*/

/*
#include<stdio.h>
#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

polynomial addPoly(polynomial, polynomial);
void printPoly(polynomial);

void main() {
	polynomial A = { 3,{4,3,5,0} };
	polynomial B = { 4,{3,1,0,2,1} };

	polynomial C;
	C = addPoly(A, B);

	printf("\n A(x) = ");
	printPoly(A);
	printf("\n B(x) = ");
	printPoly(B);
	printf("\n C(x) = ");
	printPoly(C);
	getchar();
}

polynomial addPoly(polynomial A, polynomial B) {
	polynomial C;
	int A_index = 0, B_index = 0, C_index = 0;
	int A_degree = A.degree, B_degree = B.degree;
	C.degree = MAX(A.degree, B.degree);

	while (A_index <= A.degree && B_index <= B.degree) {
		if (A_degree > B_degree) {
			C.coef[C_index++] = A.coef[A_index++];
			A_degree--;
		}
		else if (A_degree == B_degree) {
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
			A_degree--;
			B_degree--;
		}
		else {
			C.coef[C_index++] = B.coef[B_index++];
			B_degree--;
		}
	}
	return C;
}

void printPoly(polynomial P) {
	int i, degree;
	degree = P.degree;

	for (i = 0; i <= P.degree; i++) {
		printf("%3.0fx^%d", P.coef[i], degree--);
		if (i < P.degree) printf(" +");
	}
	printf("\n");
}*/

#include<stdio.h>
typedef struct {
	int row; int col; int value;
	}term;

void smTranspose(term a[], term b[]) {
	int m, n, v, i, j, p;
	m = a[0].row;
	n = a[0].col;
	v = a[0].value;
	b[0].row = n;
	b[0].col = m;
	b[0].value = v;
	if (v > 0) {
		p = 1;
		for (i = 0; i < n; i++) {
			for (j = 1; j <= v; j++) {
				if (a[j].col = i) {
					b[p].row = a[j].col;
					b[p].col = a[j].row;
					b[p].value = a[j].value;
					p++;
				}
			}
		}
	}
}