#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 50
#define CAT_MAX 35
#define MOD 1000
#define HIGH_VAL 65536

long int ws[MAX][MAX];
long int ws_bak[MAX][MAX];
long int hot_idx[MAX];
long int pure_set[MAX];
int row_num;
int col_num;
int cat_idx = 0;

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

void cat_current_array() {
    printf("The %d time of printed work sheet is :\n", cat_idx++);
    for (int i = 0; i < CAT_MAX; ++i) {
        for (int j = 0; j < CAT_MAX; ++j) {
            printf("%ld ", ws[i][j]);
        }
        putchar('\n');
    }
}

void copy_meta(long int *p_from, long int *p_to, char flag) {
    for (int i = 0; i < MAX; ++i) {
        if (flag == 'R') {
            p_to[i] = p_from[i];
        } else if (flag == 'C') {
            p_to[i * MAX] = p_from[i * MAX];
        }
    }
}

void copy_back() {
    memset(ws, '\0', sizeof(long int) * MAX * MAX);
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            ws[i][j] = ws_bak[i][j];
        }
    }
}

int main() {
    int operation_num;
    int query_num;

#ifdef LOCAL
    freopen("data/ch4-exam5.in", "r", stdin);
    freopen("data/ch4-exam5.out", "w", stdout);
#endif
    printf("Spreadsheet #1\n");
    scanf("%d %d\n", &row_num, &col_num);
    scanf("%d\n", &operation_num);
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            ws[i][j] = (i + 1) * MOD + (j + 1);
        }
        pure_set[i] = HIGH_VAL;
    }
    
    // cat_current_array();

    char key[4];
    int num;
    while(operation_num--) {
        memset(ws_bak, '\0', sizeof(long int) * MAX * MAX);
        readChars(key);
        int num_cnt = 0;
        if (key[0] == 'I' || key[0] == 'D') {
            memset(hot_idx, '\0', sizeof(long int) * MAX);
            num_cnt = readIntegers(&num) ? num : 0;
            while(num_cnt--) {
                readIntegers(&num);
                if (!hot_idx[num - 1]) {
                    hot_idx[num - 1] = 1;
                }
            }
            int bak_i = 0;
            for (int i = 0; i < MAX && bak_i < MAX; ++i) {
                if (hot_idx[i]) {
                    if (key[0] == 'I') {
                        copy_meta(pure_set, ws_bak[bak_i++], key[1]);
                    } else if (key[0] == 'D') {
                        continue;
                    }
                }
                copy_meta(ws[i], ws_bak[bak_i++], key[1]);
            }
            // row_num = bak_idx;
            cat_current_array();
            copy_back();
        } else if (key[0] == 'E' && key[1] == 'X') {
            int *swap = (int*)malloc(sizeof(int)*5);
            // int *swap_start = swap;
            while(readIntegers(&num)) {
                *swap++ = num;
                continue;
            }
            *swap++ = num;
            *swap = '\0';
            swap -= 4;
            ws[swap[2]][swap[3]] += ws[swap[0]][swap[1]];
            ws[swap[0]][swap[1]] = ws[swap[2]][swap[3]] - ws[swap[0]][swap[1]];
            ws[swap[2]][swap[3]] = ws[swap[2]][swap[3]] - ws[swap[0]][swap[1]];
        }
    }

    int row_pos;
    int col_pos;
    readIntegers(&query_num);
    while(query_num--) {
        scanf("%d %d\n", &row_pos, &col_pos);
        bool is_hit = false;
        for (int i = 0; i < MAX && !is_hit; ++i) {
            for (int j = 0; j < MAX && !is_hit; ++j) {
                if (ws[i][j] / MOD == row_pos &&
                    ws[i][j] % MOD == col_pos) {
                    printf("Cell data in (%d,%d) moved to (%d,%d)\n"
                            , row_pos, col_pos, i + 1, j + 1);
                    is_hit = true;
                }
            }
        }
        if (!is_hit) {
            printf("Cell data in (%d,%d) GONE\n", row_pos, col_pos);
        }
    }
    // Test For Push 2019/08/26.
    return 0;
}
