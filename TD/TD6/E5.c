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

    void *tab;

    /** 4. */
    ((short *) tab)[3];

    *(tab + (sizeof(short) * 3));

    /** 5. */
    ((int *) tab)[3];

    *(tab + (sizeof(int) * 3));

    return 0;
}
