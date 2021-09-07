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
