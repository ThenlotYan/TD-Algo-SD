#include <stdio.h>
#include <string.h>
#include <time.h>


int Fibonacci1(int n) {
    clock_t begin= clock();
    if (n == 0) {return n;}
    if (n == 1) {return n;}
    return Fibonacci1(n - 1) + Fibonacci1(n - 2);

}


int Fibonacci2(int n, int Tab[]) {
    if (n<=1) {return n;}
    if (Tab[n] != -1) {return Tab[n];}
    Tab[n] = Fibonacci2(n-1,Tab) + Fibonacci2(n-2,Tab);
    return Tab[n];
}
