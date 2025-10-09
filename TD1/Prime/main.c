#include <stdio.h>
#include <time.h>
#include "Prime.h"

int main() {
    long long int n = 100;
    __clock_t begin1 = clock();
    printf("Nombre de nombres premiers entre 2 et %lld (méthode naïve) : %d\n", n, compte_premiers_naif(n));
    __clock_t end1 = clock();
    printf("Temps écoulé (méthode naïve) : %lf secondes\n", (double)(end1 - begin1) / CLOCKS_PER_SEC);


    __clock_t begin2 = clock();
    printf("Nombre de nombres premiers entre 2 et %lld (Programme de Cieve) : %d\n", n, compte_premiers_cieve(n));
    __clock_t end2 = clock();
    printf("Temps écoulé (Programme de Cieve) : %lf secondes\n", (double)(end2 - begin2) / CLOCKS_PER_SEC);


    return 0;
}
