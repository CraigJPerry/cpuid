.PHONY: clean
clean:
	-rm cpuid

build:
	gcc -ansi -pedantic -Wall -o cpuid cpuid.c

