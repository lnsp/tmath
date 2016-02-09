# Compiler flags
CFLAGS=-I./include -std=gnu++11 -Wall
CFLAGS_LIB=-I./include -std=gnu++11 -c
CFLAGS_TEST=./build/libtmath.a test/tmath_test.cpp

all: lib test
	@echo Done.

lib: build_folder tmath.o
	ar rcs build/libtmath.a build/tmath.o

test: test_sine test_cosine test_tangent test_cosecant test_cotangent test_secant test_rad_deg test_abs test_factorial test_roots test_power test_exp_log test_vectors
	@echo all tests passed

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

test_cosecant: test_folder
	$(CC) $(CFLAGS) test/cosecant/test.cpp -o build/test/cosecant $(CFLAGS_TEST)
	@build/test/cosecant

test_cotangent: test_folder
	$(CC) $(CFLAGS) test/cotangent/test.cpp -o build/test/cotangent $(CFLAGS_TEST)
	@build/test/cotangent

test_secant: test_folder
	$(CC) $(CFLAGS) test/secant/test.cpp -o build/test/secant $(CFLAGS_TEST)
	@build/test/secant

test_rad_deg: test_folder
	$(CC) $(CFLAGS) test/rad-deg/test.cpp -o build/test/rad-deg $(CFLAGS_TEST)
	@build/test/rad-deg

test_abs: test_folder
	$(CC) $(CFLAGS) test/abs/test.cpp -o build/test/abs $(CFLAGS_TEST)
	@build/test/abs

test_factorial: test_folder
	$(CC) $(CFLAGS) test/factorial/test.cpp -o build/test/factorial $(CFLAGS_TEST)
	@build/test/factorial

test_roots: test_folder
	$(CC) $(CFLAGS) test/roots/test.cpp -o build/test/roots $(CFLAGS_TEST)
	@build/test/roots

test_power: test_folder
	$(CC) $(CFLAGS) test/power/test.cpp -o build/test/power $(CFLAGS_TEST)
	@build/test/power

test_exp_log: test_folder
	$(CC) $(CFLAGS) test/exp-log/test.cpp -o build/test/exp-log $(CFLAGS_TEST)
	@build/test/exp-log

test_vectors: test_folder
	$(CC) $(CFLAGS) test/vectors/test.cpp -o build/test/vectors $(CFLAGS_TEST)
	@build/test/vectors

tmath.o: build_folder
	$(CC) $(CFLAGS_LIB) src/tmath.cpp -o build/tmath.o

clean: build_folder
	rm build -f -r
