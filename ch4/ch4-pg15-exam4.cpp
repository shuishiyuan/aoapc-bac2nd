#include <stdio.h>

char book[][];

void read_book() {
    printf("Initializing the decoding book\n");
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
    read_book();
    while (true) {
        int book_row = read_digit(3);
        if (book_row == 0) {
            break;
        }
        while (true) {
            int book_col = read_digit(book_row);
            if (book_col == 1 << book_row -1) {
                break;
            }
            putchar(book[book_row][book_col]);
        }
    }
    return 0;
}
