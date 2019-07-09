/* runner.c */

#include <stdio.h>
#include <string.h>

int tests_run = 0;
int TEST_PASSED = 0;


#define TRACE_ON(fmt, ...) printf((fmt), __VA_ARGS__)
#define TRACE_OFF(fmt, ...) /**/

#define TRACE TRACE_OFF

#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); TRACE("\nreturn %d\n", r); tests_run++; if(r) return r; } while(0)
#define SUCCESS return TEST_PASSED;
#define TEST

struct Person {
    char firstname[20];
    char lastname[20];
};

void init(struct Person *param_p)
{
    strcpy(param_p->firstname, "?");
    strcpy(param_p->lastname, "?");
}


TEST int struct_01() {
    struct Person p;

    strcpy(p.firstname, "John");
    strcpy(p.lastname, "Doe");

    _assert(strcmp(p.firstname, "John") == 0);
    _assert(strcmp(p.lastname, "Doe") == 0);
    SUCCESS
}


TEST int struct_02() {
    // p is not really local. It reuse the same address of p declared in previous function.
    // Values could be already initialized by a previous treatment.
    struct Person p;

    strcpy(p.firstname, "John");
    strcpy(p.lastname, "Doe");

    init(&p);

    _assert(strcmp(p.firstname, "?") == 0);
    _assert(strcmp(p.lastname, "?") == 0);
    SUCCESS
}


int all_tests() {
    _verify(struct_01);
    _verify(struct_02);
    SUCCESS
}

int main(int argc, char **argv) {
    int result = all_tests();
    if (result == TEST_PASSED)
        printf("PASSED\n");
    else
        printf("FAILED !!!\n");
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}