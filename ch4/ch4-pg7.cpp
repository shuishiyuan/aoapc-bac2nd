#include <stdio.h>
#include <string.h>

int sum(int n[5]) {
    int result = 0;
    //int size = (int)sizeof(n);
    int size = strlen((char *)n);
    printf("The length of array is thought as: %d\n", size);
    for (int i = 0; i < size; ++i) {
        result += n[i];
    }
    return result;
}

int main () {
    printf("sum!\n");
    int n[5] = {1, 2, 3, 4, 5};
    printf("The sum of array is: %d\n", sum(n));
    return 0;
}
