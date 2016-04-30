#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/** 3. */
typedef struct {
    int x;
    int y;
} Couple;

/** 5. */
void *twist(void *couple) {
    Couple *source, *res;

    assert(couple != NULL);

    source = (Couple *) couple;
    res = (Couple *) malloc(sizeof(Couple));
    if (res == NULL)
        exit(EXIT_FAILURE);
    res->x = source->y;
    res->y = source->x;
    return res;
}

int main() {

    int a = 31;
    Couple b = {12, 777};
    Couple c = {11, -13};
    Couple *d;

    /** 1. */
    void *ptr;
    ptr = &a;

    /** 2. */
    *((int *) ptr) *= 3;
    printf("%d\n", a);

    /** 3. */
    ptr = &b;
    ((Couple *) ptr)->y += 1;
    printf("%d %d\n", b.x, b.y);

    /** 6. */
    d = twist(&c);
    printf("%d %d\n", d->x, d->y);

    return 0;
}
