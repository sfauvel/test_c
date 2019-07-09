#!/usr/bin/env bash


TEST_FILE=test/test.c
TESTNAME=$1

function write() {
    TEXT=$1
    sed -i "s/RUN_TESTS()/${TEXT}RUN_TESTS()/g" $TEST_FILE
}

function writeln() {
    write "$1\\n"
}

function write_tests() {
    grep "TEST " $TEST_FILE | while read -r test ; do
        tmp=${test}
        tmp=${tmp/TEST int /}
        tmp=${tmp/\(\) {/}
        writeln "    _verify(${tmp});"
    done

}

function build_test_file() {
    cp $1 $TEST_FILE
    tests=$(grep "TEST " test.c)s

    writeln "void all_tests() {"
    write_tests
    writeln "}"
}


build_test_file $TESTNAME


docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 make clean
docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 make all

echo "Run $TESTNAME"
docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 ./obj/test.o
