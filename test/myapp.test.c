// #include "myapp.h"
#include <assert.h>
#include <stdio.h>
#include "../include/myapp.h"

/*
Simple test with assert.
*/

static void test_something(void)
{
    printf("test_something");
    assert(1 + 1 == 2);
    printf(": ok\n");
}

static void test_with_error(void)
{
    printf("test_with_error\n");
    assert(1 + 1 == 3);
}

static void test_square(void)
{
    printf("test_with_error\n");
    assert(square(4) == 16);
}

int main(void)
{
    test_something();
    test_square();
    test_with_error();
}
