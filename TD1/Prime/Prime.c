#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Prime.h"


bool est_premier(int nombre) {
    if (nombre < 2)
        return false;
    for (int i = 2; i * i <= nombre; i++) {
        if (nombre % i == 0)
            return false;
    }
    return true;
}


int compte_premiers_naif(int n) {
    int compteur = 0;
    for (int i = 2; i <= n; i++) {
        if (est_premier(i))
            compteur++;
    }
    return compteur;
}


int compte_premiers_cieve(int n) {
    if (n < 2)
        return 0;

    bool *est_premier = malloc((n + 1) * sizeof(bool));
    if (est_premier == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return -1;
    }

    for (int i = 0; i <= n; i++)
        est_premier[i] = true;

    est_premier[0] = est_premier[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (est_premier[p]) {
            for (int multiple = p * p; multiple <= n; multiple += p) {
                est_premier[multiple] = false;
            }
        }
    }

    int compteur = 0;
    for (int i = 2; i <= n; i++) {
        if (est_premier[i])
            compteur++;
    }

    free(est_premier);
    return compteur;
}
