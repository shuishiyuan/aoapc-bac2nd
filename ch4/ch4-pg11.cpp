#include<stdio.h>

long f(int n) {
    long ret_val;
    ret_val = n == 1 ? 1 : n * f(n - 1);
    return ret_val;
}

int main() {
    printf("Factorial in Recursion\n");
    int n;
    scanf("%d", &n);
    printf("%ld", f(n));
    return 0;
}
