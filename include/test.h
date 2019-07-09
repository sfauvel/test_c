#ifndef TEST_H_   /* Include guard */
#define TEST_H_

int tests_run = 0;
int tests_failed = 0;

#define FAIL() tests_failed++;printf("\nFailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return; } } while(0)
#define _verify(test) do { tests_run++; test(); } while(0)
#define TEST

#define RUN_TESTS() int main(int argc, char **argv) { all_tests(); return runTests(); }

int runTests() {
    printf("-------------\n");
    if (tests_failed == 0)
    {
       printf("PASSED\n");
    }
    else
    {
        printf("FAILED\n");
    }
    printf("-------------\n");
    printf("Tests run: %d\nTests failed:%d\n", tests_run,tests_failed);

    return tests_failed == 0;
}

#endif // TEST_H_


