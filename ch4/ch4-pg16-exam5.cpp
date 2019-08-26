#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 50

bool readChars(char *keys) {
    char c;
    while((c = getchar()) != '\n') {
        if (c != ' ') {
            *keys++ = c;
        } else {
            *keys = '\0';
            return true;
        }
    }
    *keys = '\0';
    return false;
}

bool readIntegers(int *number) {
    *number = 0;
    char keys[4];
    bool ret_val = readChars(keys);
    int max_pow = strlen(keys) - 1;
    char c;
    char *p = keys;
    while((c = *p++) != '\0') {
        *number += pow(10, max_pow--) * (c - '0');
    }
    return ret_val;
}

int main() {
    printf("Solution a of Spreadsheet Tracking!\n");
    // int work_sheet[MAX][MAX];
    int row_num;
    int col_num;
    int operation_num;
    int query_num;

#ifdef LOCAL
    freopen("data/ch4-exam5.in", "r", stdin);
#endif
    scanf("%d %d\n", &row_num, &col_num);
    scanf("%d\n", &operation_num);
    char current_key[4];
    int current_num;
    while(operation_num--) {
        readChars(current_key);
        printf("%s", current_key);
        while(readIntegers(&current_num)) {
            printf(" %d", current_num);
        }
        printf(" %d\n", current_num);
    }

    int row_pos;
    int col_pos;
    readIntegers(&query_num);
    printf("%d\n", query_num);
    while(query_num--) {
        scanf("%d %d\n", &row_pos, &col_pos);
        printf("%d %d\n", row_pos, col_pos);
    }
    // Test For Push 2019/08/26.
    return 0;
}
