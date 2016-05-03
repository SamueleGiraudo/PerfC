#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/** 1. */
/**
 * 24 * 8 = 192 octets.
 *
 **/

/** 2. */
/** ... */

/** 3. */
/** ... */

int main() {

    short tab_entiers[] = {10, 20, 40, 70, 44, 21, 90, 999, 10, 20, 32};
    void *tab;
    int val;
    
    tab = tab_entiers;

    /** 4. */
    val = ((short *) tab)[3];
    printf("%d\n", val);
    
    val = *(((short *) tab) + 3);
    printf("%d\n", val);

    /** 5. */
    val = ((int *) tab)[3];
    printf("%d\n", val);
    
    val = *(((int *) tab) + 3);
    printf("%d\n", val);

    return 0;
}
