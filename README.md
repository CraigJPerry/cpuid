=====
cpuid
=====

Query x86 / x64 processor details, across operating systems.
Craig J Perry, <craigp84@gmail.com>

Background
==========

If we need to query CPU details of hosts, there are a few approaches
we can take:

* On Linux we can parse the file /proc/cpuinfo
* On MacOS we can parse the output of the "sysctl machdep.cpu" command
* On other BSDs we can parse the output of the "sysctl hw" command

And so on. All these operating systems expose a similar syscall(2)
which makes portability even easier. Until, we throw Windows into
the mix.

Another approach is to use the cpuid instruction in the x86 instruction
set, which is the method used here.

Please note, this code uses syntax only usable with the GCC compiler
toolchain. This is due to the need for assembly language to invoke
the cpuid instruction.

