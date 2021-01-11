#include <stdio.h>

int main() {
    printf("What is the result?\n");
    double i;
    for (i = 0; i != 1.0; i += 0.1) {
        printf("%lf\n", i);
        if (i > 2) {
            break;
        }
    }
    return 0;
}
