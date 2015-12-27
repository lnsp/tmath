# Compiler flags
CFLAGS=-I./include -std=c++11 -Wall
CFLAGS_LIB=-I./include -std=c++11 -c

all: lib test

lib: tmath.o
	mkdir -p build
	ar rcs build/libtmath.a build/tmath.o

test: test_arcsec

test_arcsec:
	mkdir -p build/test
	$(CC) $(CFLAGS) test/arcsec/test.cpp -o build/test/arcsec build/libtmath.a
	build/test/arcsec < test/arcsec/input.txt > build/test/arcsec_output.txt
	diff test/arcsec/assert.txt build/test/arcsec_output.txt

test_show:
	mkdir -p build/test
	$(CC) $(CFLAGS) test/show_values.cpp -o build/test/show build/libtmath.a

tmath.o:
	mkdir -p build
	$(CC) $(CFLAGS_LIB) src/tmath.cpp -o build/tmath.o

clean:
	rm build -f -r
