/*
 * cpuid.c: Query x86 / x64 processor details, across operating systems.
 * Craig J Perry, <craigp84@gmail.com>
 *
 * If we need to query CPU details of hosts, there are a few approaches
 * we can take:
 *
 *   On Linux we can parse the file /proc/cpuinfo
 *   On MacOS we can parse the output of the "sysctl machdep.cpu" command
 *   On other BSDs we can parse the output of the "sysctl hw" command
 * 
 * And so on. All these operating systems expose a similar syscall(2)
 * which makes portability even easier. Until, we throw Windows into
 * the mix.
 *
 * Another method is to use the cpuid instruction in the x86 instruction
 * set, which is the approach taken here.
 *
 * Please note, this code uses syntax only usable with the GCC compiler
 * toolchain. This is due to the need for assembly language to invoke
 * the cpuid instruction.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "cpuid.h"

int main(int argc, char *argv[])
{
	char *cpu = read_cpu();
	if(-1 == *cpu)
		// BUG: Leaking *cpu, however error() results in termination.
		error("Failed to read CPU.");
	free(cpu);
	return EXIT_SUCCESS;
}

char * read_cpu()
{
	char *c = malloc(sizeof *c);
	*c = -1;
	return c;
}

