#include <stdio.h>

int sum(int *n, int size) {
    int ret_val = 0;
    for (int i = 0; i < size; ++i) {
        ret_val += *(n + i);
    }
    return ret_val;
}

int main() {
    printf("sum success!\n");
    int n[] = {1, 2, 3, 4};
    printf("The sum of array is: %d\n", sum(n, 4));
    return 0;
}
