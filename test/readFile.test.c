/* runner.c */

#include <stdio.h>
#include "../include/readFile.h"
#include "../include/test.h"

TEST void readFile_non_existing_return_error() {
    char output[1024];
    _assert(read_file("", output) == 1);
}

TEST void read_existing_file() {
    char output[1024];
    read_file("resources/file_for_test.txt", output);
    _assert(strcmp(output, "File content.") == 0);
}

TEST void read_existing_file_2() {
    char output[1024];
    read_file("resources/file_for_test.txt", output);
    _assert(strcmp(output, "File content.") == 0);
}


RUN_TESTS()