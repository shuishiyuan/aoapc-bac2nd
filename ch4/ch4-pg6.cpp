#include <stdio.h>

void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void swap_ng(int *a, int *b) {
    int *temp;
    //int temp;
    *temp = *a;
    *a = *b;
    *b = *temp;
}

int main() {
    printf("swap success!\n\n");
    int a = (unsigned int)(~0) >> 1;
    int b = ((unsigned int)(~0) >> 1) + 1;
    printf("At first:\n%d\t%d\n\n", a, b);
    swap(&a, &b);
    printf("After swap:\n%d\t%d\n\n", a, b);
    swap_ng(&a, &b);
    printf("After swap_ng:\n%d\t%d\n", a, b);
    return 0;
}
