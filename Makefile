# Compiler flags
CFLAGS=-I ./include -std=c++11 -Wall
CFLAGS_LIB=-I ./include -std=c++11 -c

all: lib

lib: tmath.o
	mkdir -p build
	echo "Packaging library ..."
	ar rcs build/libtmath.a build/tmath.o

test: lib
	echo "Running tests ..."

examples: lib
	echo "Building examples ..."

tmath.o:
	echo "Building source files ..."
	mkdir -p build
	$(CC) $(CFLAGS_LIB) src/tmath.cpp -o build/tmath.o

clean:
	echo "Cleaning up ..."
	rm build -f -r
