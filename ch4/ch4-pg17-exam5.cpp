#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 50
#define MAX_INT_W 10

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

    cons_prc_info();

    dbg_cat_prc_info();

    return 0;
}
