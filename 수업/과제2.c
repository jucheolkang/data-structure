#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 30001
#define ITERATIONS 23
typedef unsigned long ULONG;
ULONG Fibonacci_Repetition(int N) { // ¹Ýº¹
    int i;
    ULONG Result;
    ULONG* FibonacciTable;
    if (N == 0 || N == 1) {
        return N;
    }
    FibonacciTable = (ULONG*)malloc(sizeof(ULONG) * (N + 1));
    FibonacciTable[0] = 0;
    FibonacciTable[1] = 1;
    for (i = 2; i <= N; i++) {
        FibonacciTable[i] = FibonacciTable[i - 1] + FibonacciTable[i - 2];
    }
    Result = FibonacciTable[N];
    free(FibonacciTable);
    return Result;
}

ULONG Fibonacci_Recursion(int N) { // Àç±Í
    int i;
    ULONG Result;
    ULONG* FibonacciTable;
    if (N == 0 || N == 1) {
        return N;
    }
    FibonacciTable = (ULONG*)malloc(sizeof(ULONG) * (N + 1));
    FibonacciTable[0] = 0;
    FibonacciTable[1] = 1;
    if (N >= 2) {
        FibonacciTable[N] = Fibonacci_Recursion(N - 1) + Fibonacci_Recursion(N - 2);
        }Result = FibonacciTable[N];
        free(FibonacciTable);
        return Result;
    

}

int main() {
    int N = 3;
    ULONG Result;
    clock_t start, stop;
    double duration;

    while (N <= 40) {
        start = clock();
        Result = Fibonacci_Repetition(N);
        stop = clock();
        duration = ((double)(stop - start)) / CLK_TCK;
        printf("Fibonacci_Repetition(%d) = %lu (time: %lf)\n", N, Result, duration);
        printf("\n");

        start = clock();
        Result = Fibonacci_Recursion(N);
        stop = clock();
        duration = ((double)(stop - start)) / CLK_TCK;
        printf("Fibonacci_Recursion(%d) = %lu (time: %lf) \n", N, Result, duration);
        printf("\n");
        printf("========================\n\n");

        N += 5;
    }
    return 0;
}