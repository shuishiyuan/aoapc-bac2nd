#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100

char decode_book[MAX_SIZE];

int calculate_base_index(int base_num) {
    int base_index = 0;
    while (--base_num >= 0 ) {
        base_index += pow(2, base_num);
    }
    return base_index;
}

int main() {
    printf("Message Decoding, ACM/ICPC World Finals 1991, UVa 213!\n");

#ifdef LOCAL
    freopen("data/ch4-pg14-exam4.in", "r", stdin);
#endif

    char c;
    scanf("%s\n", decode_book);
    printf("%s\n", decode_book);

    int base_num = 0;
    int base_index = 0;
    int offset_index = 0;
    int break_step = 3;
    bool is_book_ready = false;
    while((c = getchar()) != '\n') {
        if (break_step = 0) {
            if (is_book_ready) {
                putchar(decode_book[base_index + offset_index]);
            } else {
                if (base_num == 0) {
                    return 0;
                }
                base_index = calculate_base_index(base_num);
            }
        } else {
            ;
        }
    }
    putchar('\n');


    return 0;
}
