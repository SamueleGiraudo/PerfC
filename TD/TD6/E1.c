/** 1. et 6. */
typedef char (* ff_1)(int, int);

/** 4. */
typedef int *(* ff_2)(char *, float);

int main() {

    /** 1. */
    char (* f_1)(int, int);

    /** 2. */
    int *(* f_2)(char *, float);

    /** 3. */
    char *(* f_3)(char, char (int, int));

    /** 4. */
    ff_2 (* f_4)(char, char);

    /** 5. */
    ff_1 (* f_5)(int *(char, float));

    /** 6. */
    ff_1 tab_f_1[32];

    return 0;
}
