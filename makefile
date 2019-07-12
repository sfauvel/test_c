
CC=gcc
#CFLAGS=-Wall
CFLAGS=
SRC_PATH=src
INCLUDE_PATH=include
TEST_PATH=test
OUT_PATH=obj

SRCS = $(wildcard $(SRC_PATH)/*.c)
TESTS = $(wildcard $(TEST_PATH)/*.c)

SRC_COMPILED = $(patsubst $(SRC_PATH)/%.c,$(OUT_PATH)/%.o,$(SRCS))
TEST_COMPILED = $(patsubst $(TEST_PATH)/%.c,$(OUT_PATH)/%.o,$(TESTS))

PROGS = $(OUT_PATH)/myapp

all: $(SRC_COMPILED) $(TEST_COMPILED)


$(OUT_PATH)/%.o: $(SRC_PATH)/%.c $(INCLUDE_PATH)/%.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(OUT_PATH)/myapp.test.o:  $(INCLUDE_PATH)/myapp.h

#$(OUT_PATH)/%.o: $(TEST_PATH)/%.c
#	$(CC) $(CFLAGS) -o $@ $(SRC_COMPILED) $<

test: $(OUT_PATH)/test.o

$(OUT_PATH)/test.o: $(SRC_COMPILED)
	$(CC) $(CFLAGS) -o $(OUT_PATH)/test.o $(SRC_COMPILED) $(TEST_PATH)/test.c

$(OUT_PATH)/%.o: $(TEST_PATH)/%.c
	$(CC) $(CFLAGS) -c -o $@ $(SRC_COMPILED) $<



#############

PROG_TEST_PATH=progtest
PROG_TESTS = $(wildcard $(PROG_TEST_PATH)/*.c)
PROG_TEST_COMPILED = $(patsubst $(PROG_TEST_PATH)/%.c,$(PROG_OUT_PATH)/%.o,$(PROG_TESTS))
PROG_OUT_PATH = $(OUT_PATH)test

alltests: $(SRC_COMPILED) $(PROG_TEST_COMPILED)

$(PROG_OUT_PATH)/%.o: $(PROG_TEST_PATH)/%.c
	$(CC) $(CFLAGS) -o $@ $(SRC_COMPILED) $<

#################

callPython: $(OUT_PATH)/callPython.o

$(OUT_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -I/usr/include/python2.7 -lpython2.7 -o $@  $<

#################

shared: $(OUT_PATH)/myapp.so

$(OUT_PATH)/%.so: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $<


clean:
	rm -f $(OUT_PATH)/*
	rm -f $(PROG_OUT_PATH)/*