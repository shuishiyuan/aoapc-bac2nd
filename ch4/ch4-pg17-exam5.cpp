#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 50
#define MAX_NUM_W 10
#define MAX_KEY_W 3
#define MOD 1000

int row_num;
int col_num;
int prc_num;
int **prc;
char **prc_key;
// char (*prc_key)[MAX_KEY_W];
bool is_extra[MAX];

/* --function declaration start-- */
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

    cons_prc_info();

    ans_query();

    return 0;
}

void cons_prc_info() {
    prc = (int **)malloc(prc_num * sizeof(int *));
    prc_key = (char **)malloc(prc_num * sizeof(char *));
    char key[MAX_KEY_W];
    for (int i = 0; i < prc_num; ++i) {
        // exclude the begining 0x0a(new line character)
        if (!read_char(key)) {
            --i;
            continue;
        }
        prc_key[i] = (char *)malloc(MAX_KEY_W * sizeof(char));
        sprintf(prc_key[i], "%s", key);
        int num;
        int *num_p = (int *)malloc(sizeof(int));
        int j = 0;
        int col_w = 4;

        // Duplicate number of inserting and deleting.
        // at first, save the process number of non exchange
        if (key[0] != 'E') {
            read_num(num_p);
            num = *num_p;
            col_w = num + 1;
            prc[i] = (int *)malloc(col_w * sizeof(int));
            prc[i][j] = num;
            j++;
            memset(is_extra, false, MAX * sizeof(bool));
        } else {
            prc[i] = (int *)malloc(col_w * sizeof(int));
        }
        while (read_num(num_p)) {
            num = *num_p;
            if (key[0] != 'E' && !is_extra[num]) {
                prc[i][j] = num;
                is_extra[num] = true;
                ++j;
            } else if (key[0] == 'E') {
                prc[i][j] = num;
                ++j;
            }
        }
        num = *num_p;
        if (key[0] != 'E' && !is_extra[num]) {
            prc[i][j] = num;
        } else if (key[0] == 'E') {
            prc[i][j] = num;
        }
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
        if (prc_key[i][0] == 'E') {
            if (prc[i][0] == q_row && prc[i][1] == q_col) {
                *a_row = prc[i][2];
                *a_col = prc[i][3];
            } else if (prc[i][2] == q_row && prc[i][3] == q_col) {
                *a_row = prc[i][0];
                *a_col = prc[i][1];
            }
        } else {
            int adj_r = 0;
            int adj_c = 0;
            for (int j = 1; j <=  prc[i][0]; ++j) {
                if (prc_key[i][0] == 'I') {
                    if (prc_key[i][1] == 'R' && prc[i][j] <= q_row) adj_r++;
                    if (prc_key[i][1] == 'C' && prc[i][j] <= q_col) adj_c++;
                } else {
                    if (prc_key[i][1] == 'R' && prc[i][j] == q_row) return false;
                    if (prc_key[i][1] == 'C' && prc[i][j] == q_col) return false;
                    if (prc_key[i][1] == 'R' && prc[i][j] < q_row) adj_r--;
                    if (prc_key[i][1] == 'C' && prc[i][j] < q_col) adj_c--;
                }
            }
            *a_row += adj_r;
            *a_col += adj_c;
        }
    }
    return rtv;
}

void dbg_cat_prc_info() {
    for (int i = 0; i < prc_num; ++i) {
        int j_end = prc[i][0];
        int k = 1;
        printf("%s ", prc_key[i]);
        if (prc_key[i][0] == 'E') {
            j_end = 3;
            k = 0;
        } else {
            printf("%d ", j_end);
        }
        while (k <= j_end) {
            printf("%d ", prc[i][k]);
            ++k;
        }
        putchar('\n');
    }
}
