#include <stdio.h>

#define MAX_SIZE 100

char decode_book[MAX_SIZE];

int main() {
    printf("Message Decoding, ACM/ICPC World Finals 1991, UVa 213!\n");

#ifdef LOCAL
    freopen("data/ch4-pg14-exam4.in", "r", stdin);
#endif

    char c;
    scanf("%s\n", decode_book);
    printf("%s\n", decode_book);

    int base_index = 0;
    int offset_index = 0;
    int break_step = 3;
    while((c = getchar()) != '\n') {
        if (break_step = 0) {
            putchar(decode_book[base_index + offset_index]);
        }
    }
    putchar('\n');


    return 0;
}
