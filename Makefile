# Compiler flags
CFLAGS=-I./include -std=gnu++11 -Wall
CFLAGS_LIB=-I./include -std=gnu++11 -c
CFLAGS_TEST=test/tmath_test.cpp build/libtmath.a

all: lib test

lib: build_folder tmath.o
	ar rcs build/libtmath.a build/tmath.o

test: test_sine test_cosine test_tangent test_rad_deg test_factorial
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

test_rad_deg: test_folder
	$(CC) $(CFLAGS) test/rad-deg/test.cpp -o build/test/rad-deg $(CFLAGS_TEST)
	@build/test/rad-deg

test_abs: test_folder
	$(CC) $(CFLAGS) test/abs/test.cpp -o build/test/abs $(CFLAGS_TEST)
	@build/test/abs

test_factorial: test_folder
	$(CC) $(CFLAGS) test/factorial/test.cpp -o build/test/factorial $(CFLAGS_TEST)
	@build/test/factorial

tmath.o: build_folder
	$(CC) $(CFLAGS_LIB) src/tmath.cpp -o build/tmath.o

clean: build_folder
	rm build -f -r
