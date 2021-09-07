# Exercise 1

## Code

```cpp
#include <stdio.h>

int add(int a, int b) {
    int x = a + b;
    return x;
}

int sub(int a, int b) {
    int x = a - b;

    if (x < 0) {
        x = x * -1;
    }

    return x;
}

int mul(int a, int b) {
    int x = a * b;
    return x;
}

int div(int a, int b) {
    int x = a / b;
    return x;
}

int main() {
    printf("# Program containing several functions\n\n");
    printf("[+] Addition between 1 and 2 = %i.\n", add(1,2));
    printf("[+] Subtraction between 10 and 5 = %i.\n", sub(10,5));
    printf("[+] Multiplication between 8 and 6 = %i.\n", mul(8,6));
    printf("[+] Division between 42 and 21 = %i.\n", div(42,21));
}
```

## Compilation

Compile it into an assembly file:

```bash
gcc -S ex1.cpp
```

Object file:

```bash
gcc -c ex1.cpp
```

Compile as exe:

```bash
gcc -w -o ex1 ex1.cpp
# or gcc -w -o ex1 ex1.cpp 
```

## Locating functions

> Locating the functions in the assembly file ...

The functions are defined globally and the code is stored in sections like `_Z3addii` and `_Z3subii` (supposedly ii refers to the two integer paramters passed to the functions).

Example:

```asm
	.file	"ex1.cpp"
	.intel_syntax noprefix
	.text
	.globl	_Z3addii
	.type	_Z3addii, @function
_Z3addii:
.LFB0:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR -20[rbp], edi
	mov	DWORD PTR -24[rbp], esi
	mov	edx, DWORD PTR -20[rbp]
	mov	eax, DWORD PTR -24[rbp]
	add	eax, edx
	mov	DWORD PTR -4[rbp], eax
	mov	eax, DWORD PTR -4[rbp]
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
```

In the object file, they can be located with `objdump`:

```bash
objdump -j .text -d -M intel ex1.o

# 0000000000000000 <_Z3addii>
# ..
# 000000000000001e <_Z3subii>
# ..
# 0000000000000043 <_Z3mulii>
# ..
# 0000000000000060 <_Z3divii>
# ..
# 000000000000007d <main>
# ..
```

In the binary:

```bash
gdb -batch -ex "info functions" ./ex1

# All defined functions:
# 
# Non-debugging symbols:
# 0x0000000000001000  _init
# 0x0000000000001050  __cxa_finalize@plt
# 0x0000000000001060  puts@plt
# 0x0000000000001070  printf@plt
# 0x0000000000001080  _start
# 0x00000000000010b0  deregister_tm_clones
# 0x00000000000010e0  register_tm_clones
# 0x0000000000001120  __do_global_dtors_aux
# 0x0000000000001160  frame_dummy
# 0x0000000000001169  add(int, int)
# 0x0000000000001187  sub(int, int)
# 0x00000000000011ac  mul(int, int)
# 0x00000000000011c9  div(int, int)
# 0x00000000000011e6  main
# 0x0000000000001290  __libc_csu_init
# 0x0000000000001300  __libc_csu_fini
# 0x0000000000001308  _fini
```

And then disassemble the function with `disassemble add` for example.

Or using `objdump` the same way I did for the object file.

## Stripping

To strip the exe:

```bash
strip -o ex1.stripped ex1

# or during compilation
# 
```

