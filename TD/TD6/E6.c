#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/** 1. */
typedef void *(*fct_cmp)(void *, void *);

/** 2. */
void *min_int(void *x, void *y) {
    int *xx, *yy;

    assert(x != NULL);
    assert(y != NULL);

    xx = (int *) x;
    yy = (int *) y;

    if (*xx <= *yy)
        return x;
    return y;
}

/** 3. */
void *min_chaines(void *x, void *y) {
    char *xx, *yy;

    assert(x != NULL);
    assert(y != NULL);

    xx = (char *) x;
    yy = (char *) y;

    if (strcmp(xx, yy) <= 0)
        return x;
    return y;
}

/** 4. & 5. */
/**
 * Renvoie un pointeur sur le plus petit element d'un tableau generique.
 * - `tab` est un tableau generique.
 * - `taille` est la taille en octets occupee par un element du tableau.
 * - `nombre` et le nombre d'elements du tableau.
 * - `min` est un pointeur de fonction qui prend deux elements et renvoie
 *    le plus petit des deux.
 **/
void *min_tab(void *tab, int taille, int nombre, fct_cmp min) {
    int i;
    char *element_courant;
    char *min_trouve;


    assert(tab != NULL);
    assert(taille >= 1);
    assert(nombre >= 1);
    assert(min != NULL);

    element_courant = (char *) tab;
    min_trouve = element_courant;
    for (i = 0 ; i < nombre ; ++i) {
        min_trouve = min(element_courant, min_trouve);
        element_courant += taille;
    }
    return min_trouve;
}

int main() {
    int m_int;
    int *tab_int;
    char *m_chaine;
    char tab_chaines[4][8] = {"acaa", "bb", "aaaaac", "aab"};
    void *ptr;

    /** 6. */
    tab_int = (int *) malloc(sizeof(int) * 8);
    tab_int[0] = 11;
    tab_int[1] = 33;
    tab_int[2] = 333;
    tab_int[3] = 4;
    tab_int[4] = 178;
    tab_int[5] = 323;
    tab_int[6] = 9000;
    tab_int[7] = 5;

    ptr = min_tab(tab_int, sizeof(int), 8, min_int);
    m_int = *((int *) ptr);
    printf("%d\n", m_int);

    /** 7. */
    ptr = min_tab(tab_chaines, sizeof(char) * 8, 4, min_chaines);
    m_chaine = (char *) ptr;
    printf("%s\n", m_chaine);

    return 0;
}
