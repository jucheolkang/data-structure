#include "polynomial.h"
#include <stdio.h>
#include<stdlib.h>
polynomial* addPolynomial(polynomial* polyA, polynomial* polyB) {
	polynomial* polyC = (polynomial*)malloc(sizeof(polynomial));
	if (polyC != NULL) {
		polyC->degree = MAX(polyA->degree, polyB->degree);
		/*int A_index = 0, B_index = 0; int C_index = 0;
		int A_degree = polyA->degree, B_degree = polyB->degree; int C_degree = polyC->degree;
		while(A_index <= polyA -> degree && B_index <= polyB->degree){
		if (A_degree > B_degree){    }
		else if(A_degree == B_degree){   }
		else {   }
		}*/
		//stub coding
		polyC->coef[4] = 3; polyC->coef[3] = 5; polyC->coef[2] = 3;
		polyC->coef[1] = 7; polyC->coef[0] = 1;
	}
	return polyC;
}

polynomial* createPolynomial(int degree, float coef[]) {
	polynomial* polyP = (polynomial*)malloc(sizeof(polynomial));
	if (polyP != NULL) {
		polyP->degree = degree;
		for (int i = polyP->degree; i >= 0; i--) {
			polyP->coef[i] = coef[i];
		}
	}
	return polyP;
}

void printPolynomial(polynomial* poly) {
	if (poly != NULL) {
		printf("다항식 차수 = %d\n", poly->degree);
		for (int i = poly->degree; i >= 0; i--) {
			printf("지수 X^%d의 계수  = %0.1f\n", i, poly->coef[i]);
		}
	}
}
int main(void) {
	float coef_A[] = { 4, 3, 5, 0 };
	float coef_B[] = { 3, 1, 0, 2, 1 };
	polynomial* polyA = createPolynomial(3, coef_A);
	polynomial* polyB = createPolynomial(4, coef_B);
	polynomial* polyC = addPolynomial(polyA, polyB);
	printPolynomial(polyC);
	return 1;
}