#include<stdio.h>
#define N 10

int SumIntegers_Rep(int list[], int n) {
	int count = 0;
	int sum = 0;
	count++;
	for (int i = 0; i < n; i++) {
		count++;
		sum += list[i];
		count++;
	}
	count++;
	count++;
	printf("count(¹İº¹) = %d\n", count);
	return sum;
}

int SumIntegers_Rec(int list[], int n) {
	static int count = 0;
	if (n > 1) {
		count++;
		count++;
		return list[n - 1] + SumIntegers_Rec(list, n - 1);
	}
	count++;
	count++;
	printf("count(Àç±Í) = %d\n", count);
	return list[0];
}

int main() {
	int list[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sum = SumIntegers_Rep(list, N);
	printf("sum = %d\n", sum);

	sum = SumIntegers_Rec(list, N);
	printf("sum = %d\n", sum);
	return 1;
}