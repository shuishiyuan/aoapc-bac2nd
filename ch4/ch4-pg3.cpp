#include <stdio.h>

// the n should nether be 1 nor be too big!
int is_prime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    printf("prime number 1st\n");
    int n;
    while(scanf("%d", &n) == 1 && n > 0) {
        printf("%d is %sa prime number!\n", n, is_prime(n) ? "" : "not ");
    }
    return 0;
}
