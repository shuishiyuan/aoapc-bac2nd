#include <stdio.h>
#define MAX_ROW 10

char book[MAX_ROW][1 << MAX_ROW];

void read_book() {
    printf("Initializing the decoding book\n");
    for (int book_row = 1; book_row < MAX_ROW; ++book_row) {
        for (int book_col = 0; book_col < (1 << book_row) - 1; ++ book_col) {
            char c = getchar();
            if (c == '\n') {
                return;
            }
            book[book_row][book_col] = c;
        }
    }
}

int read_digit(int bit) {
    int digit = 0;
    while(bit--) {
        digit = 2 * digit + getchar() - '0';
    }
    return digit;
}

int main() {
    printf("Message Decoding -- Another Approach\n");
    freopen("data/ch4-exam4.in", "r", stdin);
    read_book();
    while (true) {
        int book_row = read_digit(3);
        if (book_row == 0) {
            break;
        }
        while (true) {
            int book_col = read_digit(book_row);
            if (book_col == (1 << book_row) - 1) {
                break;
            }
            putchar(book[book_row][book_col]);
        }
    }
    return 0;
}
