# Compiler flags
CFLAGS=-I./include -std=c++11 -Wall
CFLAGS_LIB=-I./include -std=c++11 -c
CFLAGS_TEST=test/tmath_test.cpp build/libtmath.a

all: lib test

lib: build_folder tmath.o
	ar rcs build/libtmath.a build/tmath.o

test: test_sine test_cosine test_tangent
	@echo All tests passed

build_folder:
	@mkdir -p build

test_folder:
	@mkdir -p build/test

test_sine: test_folder
	$(CC) $(CFLAGS) test/sine/test.cpp -o build/test/sine $(CFLAGS_TEST)
	@build/test/sine

test_cosine: test_folder
	$(CC) $(CFLAGS) test/cosine/test.cpp -o build/test/cosine $(CFLAGS_TEST)
	@build/test/cosine

test_tangent: test_folder
	$(CC) $(CFLAGS) test/tangent/test.cpp -o build/test/tangent $(CFLAGS_TEST)
	@build/test/tangent

tmath.o: build_folder
	$(CC) $(CFLAGS_LIB) src/tmath.cpp -o build/tmath.o

clean: build_folder
	rm build -f -r
