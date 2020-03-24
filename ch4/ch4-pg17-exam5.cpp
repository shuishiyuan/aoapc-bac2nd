#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 50
#define MAX_NUM_W 10
#define MAX_KEY_W 3
#define MOD 1000

int ws[MAX][MAX];
int row_num;
int col_num;
int prc_num;
int *prc;
char *prc_key;

/* --function declaration start-- */
void init_ws();
void cons_prc_info();
void ans_query();

bool read_char(char *);
bool read_num(int *);
bool apply_prc(int *, int *);

void dbg_cat_ws_info();
void dbg_cat_prc_info();
/* --function declaration end-- */

int main() {
#if LOCAL
    freopen("data/ch4-exam5.in", "r", stdin);
    freopen("data/ch4-exam5.out", "w", stdout);
#endif
    printf("Spreadsheet #1\n");
    scanf("%d %d", &row_num, &col_num);
    scanf("%d", &prc_num);
    // printf("The input row number is: %d\n", row_num);
    // printf("The input col number is: %d\n", col_num);
    // printf("The input process number is: %d\n", prc_num);

    init_ws();
    dbg_cat_ws_info();

    cons_prc_info();
    dbg_cat_prc_info();

    ans_query();

    return 0;
}

void init_ws() {
    for (int i = 0; i < row_num; ++i) {
        for (int j = 0; j < col_num; ++j) {
            ws[i][j] = (i + 1) * MOD + (j + 1);
        }
    }
}

void cons_prc_info() {
    // TODO
    // Duplicate number of inserting and deleting.
    prc = (int*)malloc(prc_num * MAX * sizeof(int));
    prc_key = (char*)malloc(prc_num * MAX_KEY_W * sizeof(char));
    char key[MAX_KEY_W];
    for (int i = 0; i < prc_num; ++i) {
        if (!read_char(key)) {
            --i;
            continue;
        }
        sprintf(prc_key + MAX_KEY_W * i, "%s", key);
        // printf("%s ", prc_key + MAX_KEY_W * i);
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

void ans_query() {
    int q_num;
    scanf("%d", &q_num);
    while (q_num-- > 0) {
        int q_row;
        int q_col;
        scanf("%d %d", &q_row, &q_col);
        
        int a_row = q_row;
        int a_col = q_col;
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
    char req[MAX_NUM_W];
    bool rtv = false;
    rtv = read_char(req);

    int exp = strlen(req) - 1;
    for (int i = 0; i <= exp; ++i) {
        *res += (req[i] - 0x30) * pow(10, exp - i);
    }
    return rtv;
}

bool apply_prc(int *a_row, int *a_col) {
    bool rtv = true;
    for (int i = 0; i < prc_num; ++i) {
        int q_row = *a_row;
        int q_col = *a_col;
        if (prc_key[MAX_KEY_W * i] == 'E') {
            if (prc[MAX * i + 0] == q_row && prc[MAX * i + 1] == q_col) {
                *a_row = prc[MAX * i + 2];
                *a_col = prc[MAX * i + 3];
            }
        } else {
            for (int j = 1; j <=  prc[MAX * i]; ++j) {
                if (prc_key[MAX_KEY_W * i] == 'I') {
                    if (prc_key[MAX_KEY_W * i + 1] == 'R') {
                        if (prc[MAX * i + j] <= q_row) {
                            (*a_row)++;
                        }
                    } else {
                        if (prc[MAX * i + j] <= q_col) {
                            (*a_col)++;
                        }
                    }
                } else {
                    if (prc_key[MAX_KEY_W * i + 1] == 'R') {
                        if (prc[MAX * i + j] == q_row) {
                            return false;
                        }
                        if (prc[MAX * i + j] < q_row) {
                            (*a_row)--;
                        }
                    } else {
                        if (prc[MAX * i + j] == q_col) {
                            return false;
                        }
                        if (prc[MAX * i + j] < q_col) {
                            (*a_col)--;
                        }
                    }
                }
            }
        }
    }
    return rtv;
}

void dbg_cat_prc_info() {
    for (int i = 0; i < prc_num; ++i) {
        int j_end = prc[MAX * i];
        int k = 1;
        printf("%s ", prc_key + MAX_KEY_W * i);
        if (prc_key[MAX_KEY_W * i] == 'E') {
            j_end = 3;
            k = 0;
        } else {
            printf("%d ", j_end);
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
