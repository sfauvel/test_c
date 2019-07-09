/* runner.c */

#include <stdio.h>
#include "../include/readFile.h"
#include "../include/test.h"

TEST void readFile_01() {
    char output[1024];
    _assert(read_file("", output) == 1);
}

TEST void read_existing_file() {
    char output[1024];
    read_file("file.txt", output);
    _assert(strcmp(output, "File content.") == 0);
}

TEST void read_existing_file_2() {
    char output[1024];
    read_file("file.txt", output);
    _assert(strcmp(output, "File content.") == 0);
}

void all_tests() {
    _verify(readFile_01);
    _verify(read_existing_file);
    _verify(read_existing_file_2);
}

RUN_TESTS()