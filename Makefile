.PHONY: clean
clean:
	-rm cpuid

build:
	gcc -o cpuid cpuid.c

