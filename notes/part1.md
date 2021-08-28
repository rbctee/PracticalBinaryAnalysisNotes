# Part 1

## Compilation Process

To show pre-processed code:

```bash
# -E to show preprocessed code
# -P to hide debug statements
gcc -E -P file.cpp
```


To show assembly code:

```bash
gcc -S -masm=intel file.cpp
```

Generate *object file*:

```bash
gcc -c file.cpp
```

> What is a *relocatable* file?

Relocatable files don't rely on being placed at any particular address inmemory; rather, they can be moved around at will without this breaking any assumptions in the code.

When you see the term relocatable in the file output, you know you're dealing with an object file and not with an executable.

> What are *symbolic references*?

In the context of linking, references that rely on a relocation symbol are called symbolic references.

When an object file references one of its own functions or variablesby absolute address, the reference will also be symbolic.

> How are references to dynamic libraries resolved by the linker?

During the linking phase, the addresses at which dynamic libraries will reside are not yet known, so references to them cannot be resolved.

Instead, the linker leaves symbolic references to these libraries even in the final executable, and these references are not resolved until the binary is actually loaded into memory to be executed.

> What does *interpreter /lib64/ld-linux-x86-64.so.2* in the following output mean?

```bash
file a.out

# a.out: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 2.6.32,BuildID[sha1]=d0e23ea731bce9de65619cadd58b14ecd8c015c7, not stripped
```

It defines which dynamic linker will be used to resolve the final dependencies on dynamic libraries when the executable is loaded into memory to be executed.

Read symbols from an ELF:

```bash
readelf --syms a.out
```

> Speaking of binary symbols, what's the diff. between DWARF and PDB?

For ELF binaries, debugging symbols are typically generated in the DWARF format, while PE binaries usually use the proprietary Microsoft Portable Debugging (PDB) format.

DWARF information is usually embedded within the binary, while PDB comes in the form of a separate symbol file.

Strip symbols from an ELF executable:

```bash
strip --strip-all a.out
```

