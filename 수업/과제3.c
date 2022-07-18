#include <stdio.h>
#include<time.h>

static int count ;
typedef unsigned long ULONG;
ULONG Fibonacci_Repetition(int N) { // ¹Ýº¹
    int i;
     count = 0;

    ULONG Result;
    ULONG* FibonacciTable;
    count++;
    if (N == 0 || N == 1) {
        count++;
        count++;
        return N;
    }
    count++;
    FibonacciTable = (ULONG*)malloc(sizeof(ULONG) * (N + 1));
    count++;
    FibonacciTable[0] = 0;
    count++;
    FibonacciTable[1] = 1;
    count++;
    for (i = 2; i <= N; i++) {
        count++;
        FibonacciTable[i] = FibonacciTable[i - 1] + FibonacciTable[i - 2];
        count++;
    }
    Result = FibonacciTable[N];
    count++;
    free(FibonacciTable);
    count++;
    count++;
    return Result;
}

ULONG Fibonacci_Recursion(int N) { // Àç±Í
    int i;
    count = 0;
    ULONG Result;
    ULONG* FibonacciTable;
    if (N == 0 || N == 1) {
        count++;
        count++;
        return N;
    }
    count++;
    FibonacciTable = (ULONG*)malloc(sizeof(ULONG) * (N + 1));
    count++;
    FibonacciTable[0] = 0;
    count++;
    FibonacciTable[1] = 1;
    count++;
    if (N >= 2) {
        count++;
        FibonacciTable[N] = Fibonacci_Recursion(N - 1) + Fibonacci_Recursion(N - 2);
        count++;
        }
    count++;
        Result = FibonacciTable[N];
        count++;
        free(FibonacciTable);
        count++;
        count++;
        return Result;
  
}

int main() {
    int N = 4;
    ULONG Result;
    clock_t start, stop;
    double duration;

    while (N <= 40) {
        start = clock();
        Result = Fibonacci_Repetition(N);
        stop = clock();
        duration = ((double)(stop - start)) / CLK_TCK;
        printf("Fibonacci_Repetition(%d) = %lu (time: %lf)\n", N, Result, duration);
        printf("count(¹Ýº¹) = %d\n", count);
        printf("\n");

        start = clock();
        Result = Fibonacci_Recursion(N);
        stop = clock();
        duration = ((double)(stop - start)) / CLK_TCK;
        printf("Fibonacci_Recursion(%d) = %lu (time: %lf) \n", N, Result, duration);
        printf("count(Àç±Í) = %d\n", count);
        printf("\n===========================\n");
        N += 5;
   }
    return 0;
}