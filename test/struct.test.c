/* runner.c */

#include <stdio.h>
#include <string.h>
#include "../include/test.h"

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
}

RUN_TESTS()