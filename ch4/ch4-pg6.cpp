#include <stdio.h>

void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    printf("swap success!\n\n");
    int a = 3;
    int b = 4;
    printf("At first:\n%d\t%d\n\n", a, b);
    swap(&a, &b);
    printf("After swap:\n%d\t%d\n", a, b);
    return 0;
}
