/* runner.c */

#include <stdio.h>
#include "../include/myapp.h"
#include "../include/test.h"

void square_01() {
    int x=5;
    _assert(square(x) == 25);
}


void square_02() {
    int x=5;
    _assert(square(x) == 27);
}

void all_tests() {
    _verify(square_01);
    _verify(square_02);
}

RUN_TESTS()