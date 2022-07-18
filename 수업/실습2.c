#include <stdio.h>
#include<time.h>
#define MAX_SIZE 30001
#define ITERATIONS 23
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void sort(int list[], int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (list[j] < list[min]) {
				min = j;
			}
			SWAP(list[i], list[min], temp);
		}
	}
}

int main()
{
	int i, j;
	int list[MAX_SIZE];
	int sizelist[] = {
		0, 10, 30, 50, 70, 90,
		100,300,500,700,900,
		1000,3000,5000, 7000, 9000,
		11000,13000, 15000, 17000, 19000,21000, 30000
	};
	clock_t start, stop;
	double duration;
	printf("\t n\t time\n");
	for (i = 0; i < ITERATIONS; i++) {
		for(j = 0; j< sizelist[i]; j++){
		list[j] = sizelist[i] - j;}
		start = clock();
		sort(list, sizelist[i]);
		stop = clock();
		duration = (double)(stop - start) / CLK_TCK;
		printf("%10d \t %10.5f\n", sizelist[i], duration);
	}
	
}