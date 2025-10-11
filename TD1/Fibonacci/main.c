#include <stdio.h>
#include <string.h>
#include <time.h>
#include "FIB.h"


void main() {
    int n = 30;
    int tabfib[n+1];
    for (int i=0; i<n+1; i++) {
    tabfib[i] = -1;
    }   


    clock_t begin= clock();
    printf("%i \n",Fibonacci1(n));
    clock_t end = clock();
    printf("Time taken: %lf\n", (double)(end - begin) / CLOCKS_PER_SEC);


    clock_t begin2= clock();
    printf("%i \n",Fibonacci2(n, (tabfib)));
        clock_t end2 = clock();
    printf("Time taken: %lf\n", (double)(end2 - begin2) / CLOCKS_PER_SEC);
}  
