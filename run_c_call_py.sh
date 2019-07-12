#!/bin/bash

function onDocker() {
    command=$@
    docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4.9 $command
}

#docker run -v $(pwd)/test:/sources -w /sources -t python_dev ls
#docker run -v $(pwd)/test:/sources -w /sources -t python_dev pip install cffi
#docker run -v $(pwd)/test:/sources -w /sources -t python_dev whoami;python --version;sudo apt install python-pip;pip install cffi;python ./test/myapp.test.py

onDocker make clean

echo "python-dev should be installed before. You can do it running:"
echo "  apt-get update"
echo "  apt-get install python-dev"
echo ""
#onDocker apt-get update;apt-get install python-dev;make callPython
onDocker make callPython

onDocker ./obj/callPython.o
