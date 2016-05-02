#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

/** 1. */
int fois_deux(int nb) {
    return 2 * nb;
}

/** 2. */
int fact(int nb) {
    if (nb <= 1)
        return nb;
    return nb * fact(nb - 1);
}

/** 3. */
void appliquer_tableau(int (*f)(int), int *tab, int n) {
    int i;

    assert(f != NULL);
    assert(tab != NULL);
    assert(n >= 0);

    for (i = 0 ; i < n ; ++ i)
        tab[i] = f(tab[i]);
}

/** 4. */

void afficher_tab(int *tab, int n) {
    int i;

    assert(tab != NULL);
    assert(n >= 0);

    for (i = 0 ; i < n ; ++i)
        printf("%d ", tab[i]);
}

/** 5. */
void appliquer_tableau_2(int (*tab_f[])(int), int *tab, int n) {
    int i;

    assert(tab_f != NULL);
    assert(tab != NULL);
    assert(n >= 0);

    for (i = 0 ; i < n ; ++ i)
        tab[i] = tab_f[i](tab[i]);
}

int main() {

    int tab[8]; /* 128 */
    int i;
    int taille = 8; /* 128 */

    srand(time(NULL));
    for (i = 0 ; i < taille ; ++i)
        tab[i] = rand() % 6;

    afficher_tab(tab, taille);
    printf("\n");

    appliquer_tableau(fois_deux, tab, taille);
    afficher_tab(tab, taille);
    printf("\n");

    appliquer_tableau(fact, tab, taille);
    afficher_tab(tab, taille);
    printf("\n");

    return 0;
}
