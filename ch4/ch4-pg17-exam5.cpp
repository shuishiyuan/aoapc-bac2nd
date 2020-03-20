#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 50
#define MAX_INT_W 10
#define MOD 1000

int ws[MAX][MAX];
int row_num;
int col_num;
int prc_num;
int *prc;
char *prc_key;

bool read_char(char *res) {
    char c;
    while((c = getchar()) != 0x20 && c != 0x0a) {
        *res++ = c;
    }
    *res = 0x00;
    if (c == 0x0a) {
        return false;
    }
    return true;
}

bool read_num(int *res) {
    *res = 0;
    char req[MAX_INT_W];
    bool rtv = false;
    rtv = read_char(req);

    int exp = strlen(req) - 1;
    for (int i = 0; i <= exp; ++i) {
        *res += (req[i] - 0x30) * pow(10, exp - i);
    }
    return rtv;
}

void dbg_cat_prc_info() {
    for (int i = 0; i < prc_num; ++i) {
        int j_end = prc[MAX * i];
        int k = 1;
        if (*(prc_key + 3 * i) == 'E') {
            j_end = 3;
            k = 0;
        }
        while (k <= j_end) {
            printf("%d ", prc[MAX * i + k]);
            ++k;
        }
        putchar('\n');
    }
}

void dbg_cat_ws_info() {
    for (int i = 0; i < row_num; ++i) {
        for (int j = 0; j < col_num; ++j) {
            printf("%d ", ws[i][j]);
        }
        putchar('\n');
    }
}

void init_ws() {
    for (int i = 0; i < row_num; ++i) {
        for (int j = 0; j < col_num; ++j) {
            ws[i][j] = (i + 1) * MOD + (j + 1);
        }
    }
}

void cons_prc_info() {
    prc = (int*)malloc(prc_num * MAX * sizeof(int));
    prc_key = (char*)malloc(prc_num * 3 * sizeof(char));
    char key[3];
    for (int i = 0; i < prc_num; ++i) {
        if (!read_char(key)) {
            --i;
            continue;
        }
        sprintf(prc_key + 3 * i, "%s", key);
        // printf("%s ", prc_key + 3 * i);
        int num;
        int j = 0;
        while (read_num(&num)) {
            prc[MAX * i + j] = num;
            // printf("%d ", prc[MAX * i + j]);
            ++j;
        }
        prc[MAX * i + j] = num;
        // printf("%d\n", num);
    }
}

bool apply_prc(int *a_row, int *a_col) {
    bool rtv = true;
    return rtv;
}

void ans_query() {
    int q_num;
    scanf("%d", &q_num);
    while (q_num-- > 0) {
        int q_row;
        int q_col;
        scanf("%d %d", &q_row, &q_col);
        
        int a_row;
        int a_col;
        bool is_there = apply_prc(&a_row, &a_col);

        if (is_there) {
            printf("Cell data in (%d,%d) moved to (%d,%d)\n"
                    ,q_row
                    ,q_col
                    ,a_row
                    ,a_col
            );
        } else {
            printf("Cell data in (%d,%d) GONE\n"
                    ,q_row
                    ,q_col
            );
        }

    }
}

int main() {
    printf("Spreadsheet #1\n");
#if LOCAL
    freopen("data/ch4-exam5.in", "r", stdin);
#endif
    scanf("%d %d", &row_num, &col_num);
    scanf("%d", &prc_num);
    printf("The input row number is: %d\n", row_num);
    printf("The input col number is: %d\n", col_num);
    printf("The input process number is: %d\n", prc_num);

    init_ws();
    dbg_cat_ws_info();

    ans_query();

    cons_prc_info();
    dbg_cat_prc_info();

    return 0;
}
