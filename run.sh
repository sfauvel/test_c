#!/usr/bin/env bash

# https://hub.docker.com/_/gcc/

#docker build -t my-gcc-app .
#docker run -it --rm --name my-running-app my-gcc-app


function old () {
    docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 gcc -o myapp myapp.c
    docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 ./myapp

    docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 gcc -o myapp.test myapp.test.c
    docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 ./myapp.test
}


TESTNAME=$1
docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 make clean
docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 make all

echo "Run $TESTNAME"
docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 ./obj/$TESTNAME.o


# With command make
#docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 make