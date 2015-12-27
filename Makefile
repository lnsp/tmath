# Compiler flags
CFLAGS=-I./include -std=c++11 -Wall
CFLAGS_LIB=-I./include -std=c++11 -c

all: lib test

lib: tmath.o
	mkdir -p build
	ar rcs build/libtmath.a build/tmath.o

test: test_sine
	@echo All tests passed

test_sine:
	mkdir -p build/test
	$(CC) $(CFLAGS) test/sine/test.cpp test/tmath_test.cpp -o build/test/sine build/libtmath.a
	build/test/sine

tmath.o:
	mkdir -p build
	$(CC) $(CFLAGS_LIB) src/tmath.cpp -o build/tmath.o

clean:
	rm build -f -r
