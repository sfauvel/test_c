#ifndef TEST_H_   /* Include guard */
#define TEST_H_

int tests_run = 0;
int tests_failed = 0;
int isFailed=0;

#define FAIL() tests_failed++;isFailed=1;printf("Failure in %s() line %d", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return; } } while(0)
#define _verify(test) do { tests_run++; test(); } while(0)
#define _verifyWithName(test, name) do { tests_run++; isFailed=0; printf("%s: ", name); test(); printf("%s\n", isFailed?"":"Ok");} while(0)
#define TEST

/*void all_tests() {} int main(int argc, char **argv) { all_tests(); return runTests(); }*/
#define RUN_TESTS()

int reportTests() {
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


