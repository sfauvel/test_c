/* runner.c */

#include <stdio.h>
//#include "sut.h"

int tests_run = 0;
int TEST_PASSED = 0;

#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); printf("return %d\n", r); tests_run++; if(r) return r; } while(0)
#define SUCCESS return TEST_PASSED;

int square_test(int val) {
    return val*val;
}

int square_01() {
    int x=5;
    _assert(square_test(x) == 25);
    SUCCESS
}


int square_02() {
    int x=5;
    _assert(square_test(x) == 27);
    SUCCESS
}

int all_tests() {
    _verify(square_01);
    _verify(square_02);
}

int main(int argc, char **argv) {
    int result = all_tests();
    if (result == TEST_PASSED)
        printf("PASSED\n");
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}