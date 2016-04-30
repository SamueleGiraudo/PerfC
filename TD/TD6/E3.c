#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

/** 1. */
int superieur(int a, int b) {
    if (a > b)
        return 1;
    if (a < b)
        return -1;
    return 0;
}

/** 2. */
int inferieur(int a, int b) {
    if (a < b)
        return 1;
    if (a > b)
        return -1;
    return 0;
}

/** 3. */
void tri(int *tab, int n, int (*comparer)(int, int)) {
    int i, i_min, j, tmp;
    for (i = 0 ; i < n - 1 ; i++) {
        i_min = i;
        for (j = i ; j < n ; j++) {
            if (comparer(tab[j], tab[i_min]) == -1)
                i_min = j;
        }
        tmp = tab[i_min];
        tab[i_min] = tab[i];
        tab[i] = tmp;
    }
}

/** 4. */

void afficher_tab(int *tab, int n) {
    int i;

    assert(tab != NULL);
    assert(n >= 0);

    for (i = 0 ; i < n ; ++i)
        printf("%d ", tab[i]);
}

int main() {

    int tab[16]; /* 2047 */
    int i;
    int taille = 16; /* 2047 */

    srand(time(NULL));
    for (i = 0 ; i < taille ; ++i)
        tab[i] = rand() % 10;

    afficher_tab(tab, taille);
    printf("\n");

    tri(tab, taille, superieur);
    afficher_tab(tab, taille);
    printf("\n");

    tri(tab, taille, inferieur);
    afficher_tab(tab, taille);
    printf("\n");

    return 0;
}
