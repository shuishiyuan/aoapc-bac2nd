#include <stdio.h>

long factorial(int n) {
    long retVal = 1;
    while (n > 0) {
        retVal *= n--;
    }
    return retVal;
}

long combinatory(int n, int m) {
    //return factorial(n) / (factorial(m) * factorial(n - m));
    return factorial(n) / factorial(m) / factorial(n - m);
}

int main() {
    printf("Combinatory 1st!\n");
    int n;
    int m;
    scanf("%d%d", &n, &m);
    printf("%ld\n", combinatory(n, m));
    return 0;
}
