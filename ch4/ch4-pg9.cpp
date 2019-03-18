#include <stdio.h>

int sum_start_end_index(int *start, int *end) {
    int ret_val = 0;
    int size = end - start;
    for (int i = 0; i < size; ++i) {
        ret_val += start[i];
    }
    return ret_val;
}

int sum_start_end_pointer(int *start, int *end) {
    int ret_val = 0;
    for (int *p = start; p < end; ++p) {
        ret_val += *p;
    }
    return ret_val;
}

int main() {
    printf("sum success using start and end position!\n");
    int n[] = {1, 2, 3, 4};
    printf("sum_start_end_index: %d\n", sum_start_end_index(n, n + 4));
    printf("sum_start_end_pointer: %d\n", sum_start_end_pointer(n, n + 4));
    return 0;
}
