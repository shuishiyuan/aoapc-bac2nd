#include <stdio.h>

long long factorial(int n) {
    long long retVal = 1;
    while (n > 0) {
        retVal *= n--;
    }
    return retVal;
}

long long permutation(int n, int m) {
    long long retVal = 1;
    int i =  n - m + 1;
    while (i <= n) {
        retVal *= i++;
    }
    return retVal;
}

long long combinatory(int n, int m) {
    if (m > n / 2) {
        m = n - m;
    }
    /*long long retVal = permutation(n, m);
    while (m > 0) {
        retVal /= m--;
    }
    return  retVal;*/
    return permutation(n, m) / factorial(m);
}

int main() {
    printf("Combinatory 2nd.\n");
    printf("Please input n, m:\n");
    int n, m;
    scanf("%d%d", &n, &m);
    /*printf("permutation(n, m): %.0lf\n", permutation(n, m));
    printf("factorial(m): %.0lf\n", factorial(m));
    printf("permutation(n, m) / factorial(m): %.0lf\n", permutation(n, m) / factorial(m));
    printf("combinatory(n, m): %.0lf\n", combinatory(n, m));*/
    printf("permutation(n, m): %lld\n", permutation(n, m));
    printf("factorial(m): %lld\n", factorial(m));
    printf("permutation(n, m) / factorial(m): %lld\n", permutation(n, m) / factorial(m));
    printf("combinatory(n, m): %lld\n", combinatory(n, m));
    return 0;
}
