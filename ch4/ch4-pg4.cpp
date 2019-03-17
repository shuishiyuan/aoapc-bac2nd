#include <stdio.h>
#include <math.h>

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }

    int n_border = floor(sqrt(n) + 0.5);
    for(int i = 2; i <= n_border; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    printf("prime number 2nd!\n");
    int n;
    while(scanf("%d", &n) == 1 && n != 0) {
        printf("%d is %sa prime number!\n", n, is_prime(n) ? "" : "NOT ");
    }
    return 0;
}
