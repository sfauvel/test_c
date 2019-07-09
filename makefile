
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

$(OUT_PATH)/%.o: $(TEST_PATH)/%.c
	$(CC) $(CFLAGS) -o $@ $(SRC_COMPILED) $<

clean:
	rm -f $(OUT_PATH)/*