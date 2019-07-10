/* runner.c */

#include <stdio.h>
#include "../include/myapp.h"
#include "../include/test.h"

TEST void square_01() {
    int x=5;
    _assert(square(x) == 25);
}


TEST void square_02() {
    int x=5;
    _assert(square(x) == 27);
}

RUN_TESTS()